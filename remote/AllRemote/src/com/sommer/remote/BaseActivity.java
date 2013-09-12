package com.sommer.remote;

import java.util.ArrayList;
import java.util.HashMap;

import com.sommer.allremote.R;



import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.DialogInterface.OnKeyListener;
import android.content.res.TypedArray;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.View;
import android.widget.AdapterView;
import android.widget.GridView;
import android.widget.SimpleAdapter;
import android.widget.AdapterView.OnItemClickListener;




public class BaseActivity extends Activity {
	
	private boolean isMore = false;
	AlertDialog menuDialog;
	GridView menuGrid;
	View menuView;
	
	private final int ITEM_SEARCH = 0;
	private final int ITEM_FILE_MANAGER = 1;
	private final int ITEM_DOWN_MANAGER = 2;
	private final int ITEM_FULLSCREEN = 3;
	private final int ITEM_MORE = 11;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
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
				case ITEM_SEARCH:
				
				
					break;
				case ITEM_FILE_MANAGER:

					break;
				case ITEM_DOWN_MANAGER:

					break;
				case ITEM_FULLSCREEN:

					break;
				case ITEM_MORE:// ��ҳ
					if (isMore) {
//						menuGrid.setAdapter(getMenuAdapter(menu_name_array2,
//								menu_image_array2));
						isMore = false;
					} else {// ��ҳ
//						menuGrid.setAdapter(getMenuAdapter(menu_name_array,
//								menu_image_array));
						isMore = true;
					}
					menuGrid.invalidate();// ����menu
					menuGrid.setSelection(ITEM_MORE);
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
