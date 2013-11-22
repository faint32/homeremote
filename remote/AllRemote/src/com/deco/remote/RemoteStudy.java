package com.deco.remote;

import com.deco.allremote.R;
import com.deco.data.Value;
import com.deco.ircore.RemoteCommunicate;



import android.app.Activity;
import android.os.Bundle;

import android.view.View;

public class RemoteStudy extends Activity {
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.dialog_study);
//		DisplayMetrics dm = new DisplayMetrics();
//		Display display = getWindowManager().getDefaultDisplay();
//		display.getMetrics(dm);
//		int screenWidth = dm.widthPixels;
//		int screenHeight = dm.heightPixels;
		
		
		
//		Button studyExit = (Button) findViewById(R.id.button_study_exit);
//		studyExit.setOnClickListener(this);
//		studyExit.setWidth((screenWidth) / 3);
//		studyExit.setHeight((screenHeight) / 10);

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
	
		case R.id.study_Left:
			RemoteCommunicate.remoteDECOLearnStop();
			  Bundle bundle = new Bundle();  
			  bundle.putInt("status", -1);
		Value.isStudying = false;
		setResult(RESULT_CANCELED, getIntent().putExtras(bundle)); 
			finish();
			break;
		}
	}
	
	
}
