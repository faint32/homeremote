package com.sommer.ui;


import com.sommer.allremote.R;
import com.sommer.data.Value;

import android.app.Dialog;
import android.content.Context;
import android.view.View.OnClickListener;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Toast;

public class QuitDialog extends Dialog implements OnClickListener{
	Context mContext;
	Button quitButton= null;
	Button returnButton = null;
	
	public QuitDialog(Context context) {
		super(context);
		mContext =context;
		// TODO Auto-generated constructor stub
	}

	
	 /** 
     * 自定义Dialog监听器 
     */  
    public interface PriorityListener {  
       
        public void quitApplication( );  
    }  
      
    private PriorityListener listener;  
    
    /** 
     * 带监听器参数的构造函数 
     */  
    public QuitDialog(Context context, int theme, PriorityListener listener) {  
        super(context, theme); 
        mContext =context;
        this.listener = listener;  
    }  

	public QuitDialog(Context context, int theme) {
		super(context, theme);
		// TODO Auto-generated constructor stub
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.dialog_quit);
		quitButton = (Button) findViewById(R.id.quit_ok);
		returnButton = (Button) findViewById(R.id.quit_cancle);
		quitButton.setOnClickListener(this);
		returnButton.setOnClickListener(this);	
		
	}
	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
	
		if (v.getId()==R.id.quit_ok){
		this.dismiss();	
		listener.quitApplication();
		}
		if (v.getId()==R.id.quit_cancle){
		this.dismiss();	
		
		}
    	
	}

	

}
