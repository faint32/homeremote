package com.sommer.ui;



import com.sommer.allremote.R;

import android.app.Activity;
import android.content.Context;
import android.graphics.drawable.ColorDrawable;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.PopupWindow;

public class SelectPicPopupWindow extends PopupWindow {


	private Button btn_study, btn_options, btn_quit,btn_about;
	private View mMenuView;

	public SelectPicPopupWindow(Activity context,OnClickListener itemsOnClick) {
		super(context);
		LayoutInflater inflater = (LayoutInflater) context
				.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		mMenuView = inflater.inflate(R.layout.popup_window, null);
		btn_study = (Button) mMenuView.findViewById(R.id.btn_study);
		btn_options = (Button) mMenuView.findViewById(R.id.btn_options);
		btn_quit = (Button) mMenuView.findViewById(R.id.btn_quit);
		btn_about =(Button) mMenuView.findViewById(R.id.btn_about);
//		btn_quit.setOnClickListener(new OnClickListener() {
//
//			public void onClick(View v) {
//				
//				dismiss();
//			}
//		});
		btn_quit.setOnClickListener(itemsOnClick);
		btn_about.setOnClickListener(itemsOnClick);
		btn_study.setOnClickListener(itemsOnClick);
		btn_options.setOnClickListener(itemsOnClick);

		this.setContentView(mMenuView);
	
		this.setWidth(LayoutParams.FILL_PARENT);
	
		this.setHeight(LayoutParams.WRAP_CONTENT);

		this.setFocusable(true);

		this.setAnimationStyle(R.style.AnimBottom);
	
		ColorDrawable dw = new ColorDrawable(0xb0000000);
	
		this.setBackgroundDrawable(dw);
	
		mMenuView.setOnTouchListener(new OnTouchListener() {
			
			public boolean onTouch(View v, MotionEvent event) {
				
				int height = mMenuView.findViewById(R.id.pop_layout).getTop();
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
