package com.sommer.remote;

import java.util.ArrayList;
import java.util.HashMap;

import com.sommer.allremote.R;
import com.sommer.data.Value;




import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.DialogInterface.OnKeyListener;
import android.content.res.TypedArray;
import android.os.Bundle;

import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.View;
import android.widget.AdapterView;
import android.widget.GridView;
import android.widget.SimpleAdapter;

import android.widget.AdapterView.OnItemClickListener;




public class BaseActivity extends Activity {
	

	AlertDialog menuDialog;
	GridView menuGrid;
	View menuView;
	private static Context mContext;
	
	private final int ITEM_LIST = 0;
	private final int ITEM_STUDY = 1;
	private final int ITEM_SETTING = 2;
	private final int ITEM_ABOUT = 3;
	private final int ITEM_QUIT = 4;
	private final int ITEM_RETURN = 5;
	@SuppressLint("Recycle")
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		mContext=this;
		menuView = View.inflate(this, R.layout.gridview_menu, null);

		menuDialog = new AlertDialog.Builder(this).create();
		menuDialog.setView(menuView);
		menuDialog.setOnKeyListener(new OnKeyListener() {
			public boolean onKey(DialogInterface dialog, int keyCode,
					KeyEvent event) {
				if (keyCode == KeyEvent.KEYCODE_MENU)
					dialog.dismiss();
				return false;
			}
		});

		menuGrid = (GridView) menuView.findViewById(R.id.gridview);
		TypedArray imgs = getResources().obtainTypedArray(R.array.menu_image_base);
		String[] menu_name_base = getResources().getStringArray(R.array.menu_name_base);
		
		menuGrid.setAdapter(getMenuAdapter(menu_name_base, imgs));

		menuGrid.setOnItemClickListener(new OnItemClickListener() {
			public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
					long arg3) {
				switch (arg2) {
				case ITEM_LIST:
					Intent optionsIntent = new Intent(mContext, RemoteDevicesList.class);
					startActivity(optionsIntent);
					break;
				
				case ITEM_STUDY:
//					mHandler.obtainMessage(R.id.MSG_OPTION_STUDY, 1, -1)
//					.sendToTarget();	
					Value.isStudying = true;
					Intent studyIntent = new Intent(mContext, StudyActivity.class);
					startActivityForResult(studyIntent, R.id.REQUEST_STUDY);  
					break;
				case ITEM_SETTING:
					
					break;
				case ITEM_QUIT:

					AlertDialog.Builder builder = new AlertDialog.Builder(mContext);
					builder.setTitle(getString(R.string.str_title));
					builder.setMessage(getString(R.string.str_message));
					builder.setPositiveButton(getString(R.string.str_ok),
							new DialogInterface.OnClickListener() {
								public void onClick(DialogInterface dialog, int which) {
									dialog.dismiss();
									menuDialog.dismiss();
									finish();
								}
							});
					builder.setNeutralButton(getString(R.string.str_back),
							new DialogInterface.OnClickListener() {
								public void onClick(DialogInterface dialog, int which) {
									dialog.dismiss();
								}
							});
					builder.show();
					break;
				case ITEM_ABOUT:
					LayoutInflater mInflater = LayoutInflater.from(mContext);
					View settingView = mInflater.inflate(R.layout.about_dialog, null);
					AlertDialog aboutDialog = new AlertDialog.Builder(mContext)
							.setIcon(R.drawable.ic_launcher)
							.setTitle(R.string.title_about)
							.setView(settingView)
							.setPositiveButton(R.string.dialog_ok,
									new DialogInterface.OnClickListener() {
										public void onClick(DialogInterface dialog,
												int whichButton) {
										}
									}).create();
					aboutDialog.show();
					break;
				case ITEM_RETURN:
					menuDialog.dismiss();
					break;
				default:
					break;
					
				}
				
				
			}
		});
	}
	
	
	


	
	
	
	private SimpleAdapter getMenuAdapter(String[] menuNameArray,
			Object imageResourceArray) {
		ArrayList<HashMap<String, Object>> data = new ArrayList<HashMap<String, Object>>();
		for (int i = 0; i < menuNameArray.length; i++) {
			HashMap<String, Object> map = new HashMap<String, Object>();
			map.put("itemImage", (int)((TypedArray) imageResourceArray).getResourceId(i,0));
			map.put("itemText", menuNameArray[i]);
			data.add(map);
		}
		SimpleAdapter simperAdapter = new SimpleAdapter(this, data,
				R.layout.item_menu, new String[] { "itemImage", "itemText" },
				new int[] { R.id.item_image, R.id.item_text });
		return simperAdapter;
	}
	@Override
	public boolean onMenuOpened(int featureId, Menu menu) {
		
		if (menuDialog == null) {
			menuDialog = new AlertDialog.Builder(this).setView(menuView).show();
		} else {
			menuDialog.show();
		}
		return false;
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		menu.add("menu");
		return super.onCreateOptionsMenu(menu);
	}
	
		
			

	
}
