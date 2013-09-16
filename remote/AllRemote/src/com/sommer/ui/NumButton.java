package com.sommer.ui;



import com.sommer.allremote.R;
import com.sommer.data.Value;

import android.app.Activity;
import android.content.Context;
import android.graphics.drawable.ColorDrawable;
import android.util.DisplayMetrics;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.PopupWindow;

public class NumButton extends PopupWindow {


	private Button btn_num0, btn_num1, btn_num2,btn_num3,btn_num4
	,btn_num5,btn_num6,btn_num7,btn_num8,btn_num9,btn_num10,btn_bck;
	private View mNumView;

	public NumButton(Activity context,OnClickListener itemsOnClick) {
		super(context);
		
		LayoutInflater inflater = (LayoutInflater) context
				.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		mNumView = inflater.inflate(R.layout.popup_button_number, null);
		btn_num0 = (Button) mNumView.findViewById(R.id.bt_num0);
		
		btn_num1 = (Button) mNumView.findViewById(R.id.bt_num1);
	
		btn_num2 = (Button) mNumView.findViewById(R.id.bt_num2);
	
		btn_num3 =(Button) mNumView.findViewById(R.id.bt_num3);
		
		btn_num4 = (Button) mNumView.findViewById(R.id.bt_num4);
	
		btn_num5 = (Button) mNumView.findViewById(R.id.bt_num5);
	
		btn_num6 = (Button) mNumView.findViewById(R.id.bt_num6);
	
		btn_num7 =(Button) mNumView.findViewById(R.id.bt_num7);
	
		btn_num8 = (Button) mNumView.findViewById(R.id.bt_num8);
	
		btn_num9 = (Button) mNumView.findViewById(R.id.bt_num9);
		
		btn_num0 = (Button) mNumView.findViewById(R.id.bt_num0);
	
		btn_num10 =(Button) mNumView.findViewById(R.id.bt_num10);
	
		btn_bck =(Button) mNumView.findViewById(R.id.bt_bck);
	
		
		btn_num0.setOnClickListener(itemsOnClick);
		btn_num1.setOnClickListener(itemsOnClick);
		btn_num2.setOnClickListener(itemsOnClick);
		btn_num3.setOnClickListener(itemsOnClick);

		this.setContentView(mNumView);
	
		this.setWidth(LayoutParams.FILL_PARENT);
	
		this.setHeight(LayoutParams.WRAP_CONTENT);

		this.setFocusable(true);

		this.setAnimationStyle(R.style.AnimBottom);
	
		ColorDrawable dw = new ColorDrawable(0xb0000000);
	
		this.setBackgroundDrawable(dw);
	
		mNumView.setOnTouchListener(new OnTouchListener() {
			
			public boolean onTouch(View v, MotionEvent event) {
				
				int height = mNumView.findViewById(R.id.pop_num_button).getTop();
				int y=(int) event.getY();
				if(event.getAction()==MotionEvent.ACTION_UP){
					if(y<height){
						dismiss();
					}
				}				
				return true;
			}
		});

	}

}
