package com.sommer.ircomm;


import java.util.Arrays;


import android.media.AudioFormat;
import android.media.AudioTrack;
import android.util.Log;






	public class EncoderCore{

		private final static String TAG = "EncoderCore";
		
		private final static int SampleRate = 44100;
	//	private final static int MINTIME = 10000/441;
		

		
		private final static int rmtBuffSize = AudioTrack.getMinBufferSize(SampleRate, AudioFormat.CHANNEL_OUT_STEREO, AudioFormat.ENCODING_PCM_8BIT);

		

//		private final int pwBuffSize = PowerSupply.pwMinBufferSize;
		
		private static  int encoderBufferSize;
		private  static byte[] SignalData = {-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67
			,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67
			,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67
			,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67,-128,-128,-74,74,29,-29,-4,4,2,-2,-26,26,67,-67
		};
		private  static byte[] Signal8000 = { 
			-128,-128,-18,18,-18,18,127,-127,18,-18
		};
		private  static byte[] Signal1000 = { 
			-128,-128,-111,111,-95,95,-79,79,-64,64,-51,51,-38,38,-27,27,-18,18,-11,11,-5,5,-2,2,-1,1,-2,2,-5,5,-11,11,-18,18,-27,27,-38,38,-51,51,-65,65,-79,79,-95,95,-111,111,-128,-128,111,-111,95,-95,79,-79,64,-64,51,-51,38,-38,27,-27,18,-18,11,-11,5,-5,2,-2,1,-1,2,-2,5,-5,11,-11,18,-18,27,-27,38,-38,51,-51,65,-65,79,-79,95,-95,111,-111
		};
		
		private  static byte[] Signal6500 = { 
			-128,-128,-33,33,-2,2,-57,57,95,-95,14,-14,11,-11
		};
		private  static byte[] Signal8500 = { 
			-128,-128,-14,14,-27,27,103,-103,5,-5	
		};
		private  static byte[] Signal9000 = { 
			-128,-128,-11,11,-39,39,78,-78,1,-1
		};
		private  static byte[] Signal9500 = { 
			-128,-128,-8,8,-51,51,58,-58,5,-5	
		};
		private  static byte[] Signal10000= { 
			-128,-128,-5,5,-65,65,38,-38
		};
		private  static byte[] Signal11000 = { 
			-128,-128,-8,8,-51,51,58,-58,5,-5	
		};
		private  static byte[] Signal12000 = { 
			-128,-128,-1,1,126,-126	
		};
		private  static byte[] Signa13000= { 
			-128,-128,-2,2,95,-95
		};
		private  static byte[] Signal3250= { 
			-128,-128,-76,76,-33,33,-6,6,-2,2,-20,20,-57,57,-107,107,95,-95,47,-47,14,-14,1,-1,11,-11,41,-41
		};
		
		public static int getRmtBuffSize(){
			return rmtBuffSize;
		}

//		public int getPowerBuffSize(){
//			return pwBuffSize;   
//		}

		public  static int getMsgSamplerate(){
			return SampleRate;
		}
		
		public  static int getPowerSupplySamplerate(){
			return SampleRate;
		}
		
//		public native static int getEncoderBufferSize();
		public static int getEncoderBufferSize(){
			return encoderBufferSize;
			
		}
		
		public static byte[] getComData(byte[] data) {
			
			int m;
			byte[] waveform = new byte[14000];
			boolean[] bits = new boolean[data.length*8];
		//	byte[] waveform = new byte[(sendme.length*bytesinframe*sampleRate / baudRate)]; // 8 bit, no parity, 1 stop
			//Arrays.fill(waveform, (byte) 0);
			Arrays.fill(bits, true); // slight opti to decide what to do with stop bits
			m=0;
			// generate bit array first: makes it easier to understand what's going on
			for (int i=0;i<data.length;++i)
			{

				bits[m++]=((data[i]&1)==1);//?false:true;
				bits[m++]=((data[i]&2)==2);//?false:true;
				bits[m++]=((data[i]&4)==4);//?false:true;
				bits[m++]=((data[i]&8)==8);//?false:true;
				bits[m++]=((data[i]&16)==16);//?false:true;
				bits[m++]=((data[i]&32)==32);//?false:true;
				bits[m++]=((data[i]&64)==64);//?false:true;
				bits[m++]=((data[i]&128)==128);//?false:true;
				
			}
			
			// now generate the actual waveform using l to wiggle the DAC and prevent it from zeroing out
			int point =0;
//			System.arraycopy(Signal3250, 0, waveform, point, Signal3250.length);
//			point += Signal3250.length;
			for (int i=0;i<bits.length;i++ ){
			//	Log.v(TAG, "bits value  " + i + "is " + bits[i] );
				if (bits[i]==false){
				System.arraycopy(Signa13000, 0, waveform, point, Signa13000.length);
				point += Signa13000.length;
				}
				else{
				System.arraycopy(Signal6500, 0, waveform, point, Signal6500.length);
				point += Signal6500.length;
				}
				
			}
			

//			for (int i=0;i<waveform.length;i++ ){
//				Log.v(TAG, "waveform value  " + i + "is " + waveform[i] );
//				
//			}
			byte[] wavetemp = new byte[point];
			System.arraycopy(waveform, 0, wavetemp, 0,point);
			
			return wavetemp;
			
		}
		
		
	

		

}
	
