package com.deco.ui;


import com.deco.allremote.R;
import com.deco.data.Value;

import android.app.Dialog;
import android.content.Context;
import android.view.View.OnClickListener;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Toast;

public class InputNameDialog extends Dialog implements OnClickListener{
	Context mContext;
	ImageButton dlgConfirm= null;
	EditText nameChgInput = null;
	
	public InputNameDialog(Context context) {
		super(context);
		mContext =context;
		// TODO Auto-generated constructor stub
	}

	
	 /** 
     * 自定义Dialog监听器 
     */  
    public interface PriorityListener {  
        /** 
         * 回调函数，用于在Dialog的监听事件触发后刷新Activity的UI显示 
         */  
        public void refreshDeviceName(String string);  
    }  
      
    private PriorityListener listener;  
    /** 
     * 带监听器参数的构造函数 
     */  
    public InputNameDialog(Context context, int theme, PriorityListener listener) {  
        super(context, theme); 
        mContext =context;
        this.listener = listener;  
    }  


	




	public InputNameDialog(Context context, int theme) {
		super(context, theme);
		// TODO Auto-generated constructor stub
	}


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.dialog_inputname);
		dlgConfirm = (ImageButton) findViewById(R.id.dlg_confirm);
		nameChgInput = (EditText) findViewById(R.id.dlg_input);
		nameChgInput.setText(Value.rmtDev.getName());
		dlgConfirm.setOnClickListener(this);

			
		
	}
	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
	
		if (v.getId()==R.id.dlg_confirm){
			if (nameChgInput.getText().toString()!=null){
				Value.rmtDev.setName(nameChgInput.getText().toString());
				listener.refreshDeviceName(nameChgInput.getText().toString());
				dismiss();
			}else{
			Toast.makeText(mContext, "please input name", Toast.LENGTH_LONG).show();	
			}
		
		}
    	
	}

}
