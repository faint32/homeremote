package com.sommer.remote;



import com.etek.ircomm.RemoteComm;
import com.sommer.allremote.R;
import com.sommer.data.Value;



import android.annotation.SuppressLint;
import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.DisplayMetrics;
import android.view.Display;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class StudyActivity extends Activity implements OnClickListener{
	 StudyHandler studyHandler;
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.dialog_studyed);
		DisplayMetrics dm = new DisplayMetrics();
		Display display = getWindowManager().getDefaultDisplay();
		display.getMetrics(dm);
		int screenWidth = dm.widthPixels;
		int screenHeight = dm.heightPixels;
		
		
		
		Button studyExit = (Button) findViewById(R.id.button_study_exit);
		studyExit.setOnClickListener(this);
		studyExit.setWidth((screenWidth) / 3);
		studyExit.setHeight((screenHeight) / 10);
		studyHandler = new StudyHandler();  
          StudyThread thread = new StudyThread();  
          thread.start();  
	}
	
	
	

	@Override
	protected void onStart() {
		// TODO Auto-generated method stub
		super.onStart();
	
	}




	public void onClick(View arg0) {
		// TODO Auto-generated method stub
		switch(arg0.getId())
		{
	
		case R.id.button_study_exit:
			RemoteComm.remoteLearnStop();
		Value.isStudying = false;
			finish();
			break;
		}
	}
	
	  @SuppressLint("HandlerLeak")
	private class StudyHandler  extends Handler{ 
		  
		  
	    
	        @Override  
	        public void handleMessage(Message msg) {  
	            // TODO Auto-generated method stub  
	            super.handleMessage(msg);  
	            Bundle bundle = msg.getData();  
	            int status = bundle.getInt("status");
	          if (status==-1){
	        	  RemoteComm.remoteLearnStop();
	      		Value.isStudying = false;
	      		setResult(RESULT_CANCELED, getIntent().putExtras(bundle)); 
	      		finish();
	          }else if(status==0){
	        	  RemoteComm.remoteLearnStop();
		      		Value.isStudying = false;
		      		setResult(RESULT_CANCELED, getIntent().putExtras(bundle)); 
		      		finish();  
	          }else {
	        	  setResult(RESULT_OK, getIntent().putExtras(bundle)); 
	        	finish();  
	          }
	        }  
	    }  
	    private class StudyThread extends Thread{ 
	    	int status;
	        @Override  
	        public void run() {  
	            status=	RemoteComm.learnRemoteLoop(30);  
	          
	            Message msg = new Message();  
	            Bundle bundle = new Bundle();  
	            bundle.putInt("status", status);  
	            msg.setData(bundle);  
	            StudyActivity.this.studyHandler.sendMessage(msg);  
	              
	        }  
	    }  
	
}