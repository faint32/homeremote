package com.sommer.ircomm;



import java.util.Arrays;
import java.util.LinkedList;

import com.sommer.data.RemoteData;



import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.SystemClock;
import android.util.Log;

public class RemoteOut {
	// idea from http://marblemice.blogspot.com/2010/04/generate-and-play-tone-in-android.html as modified by Steve Pomeroy <steve@staticfree.info>

	private  static Thread audiothread = null;
	private  static AudioTrack audiotrk = null;
	private  static byte generatedSnd[] = null;
	private final static String TAG ="RemoteOut";

	// set that is actually used: this is so they get upadted all in one go (safer)
	
	private static int sampleRate = 44100;
	

	public static LinkedList<byte[]> playque = new LinkedList<byte[]>();
	public static boolean active = false;
	private static int minbufsize;
	private static int length;



	// essentially a constructor, but i prefer to do a manual call.
	public static void activate() {
	//	UpdateParameters(true);

		// Use a new tread as this can take a while
		audiothread = new Thread(){
			public void run() {
				active = true;
				synchronized(audiothread)
				{
					while(active)
					{
						try {
							audiothread.wait(Long.MAX_VALUE);
							while (playque.isEmpty()==false)
								playSound();
						} catch (InterruptedException e) {e.printStackTrace();}
					}
				}
			}
		};
		audiothread.start();
		while(active == false) // wait for the thread to actually turn on
		{
			SystemClock.sleep(50);
		}
	}

	public static boolean isPlaying()
	{
		try{return audiotrk.getPlaybackHeadPosition() < (generatedSnd.length);}catch(Exception e){return false;}
	}




	@SuppressWarnings("deprecation")
	private static void playSound(){
		if (audiotrk != null)
		{
//			if (generatedSnd != null)
//			{
//				
//				
////				while (audiotrk.getPlaybackHeadPosition() < (generatedSnd.length)){
////					Log.v(TAG, "wait generatedsnd  ");
////					SystemClock.sleep(100);  // let existing sample finish first: this can probably be set to a smarter number using the information above
////				}
//			}
			audiotrk.release();
		}
		minbufsize=EncoderCore.getRmtBuffSize();
	//	UpdateParameters(false); // might as well do it at every iteration, it's cheap
		generatedSnd = playque.poll();
		length = generatedSnd.length;
		Log.v(TAG, "length ===========> " + length);
		if (minbufsize<length)
			minbufsize=length;
		audiotrk = new AudioTrack(AudioManager.STREAM_MUSIC,
				sampleRate, AudioFormat.CHANNEL_OUT_STEREO,
				AudioFormat.ENCODING_PCM_8BIT, minbufsize,
				AudioTrack.MODE_STATIC);
		Log.v(TAG, "sampleRate ===========> " + sampleRate);
		Log.v(TAG, "minbufsize ===========> " + minbufsize);
		audiotrk.setStereoVolume(1,1);
		audiotrk.write(generatedSnd, 0, length); 
		audiotrk.play();
	}


	public static void sendRemote(String keyValue) {
		// TODO Auto-generated method stub
		if (keyValue==null)
			return;
		playque.add(EncoderCore.getRemoteFrameData( keyValue));
		synchronized(audiothread) {audiothread.notify();}
	}
}

