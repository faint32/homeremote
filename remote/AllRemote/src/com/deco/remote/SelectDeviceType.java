package com.deco.remote;

import com.deco.adapt.DeviceAdapter;

import com.deco.allremote.R;
import com.deco.data.RemoteDevice;
import com.deco.data.Value;
import com.deco.remote.RemoteDevicesList.LISTSTATUS;
import com.deco.ui.InputNameDialog;

import android.app.Activity;
import android.app.Dialog;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.TextView;

import android.widget.ImageButton;
import android.widget.ListView;


public class SelectDeviceType extends Activity implements OnClickListener, OnItemClickListener{
	
	private ListView listView;
	private ImageButton dtlBack;
	private ImageButton dtlEnter;

	private int mType;
	private SelectDeviceType mContext;
	private DeviceAdapter typeAdapter;
	private Button dtlName;
	private TextView tvName;
	public void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.device_type_list);
	        
	        dtlBack= (ImageButton)findViewById(R.id.dtl_left);
	        dtlBack.setOnClickListener(this);
	        dtlEnter= (ImageButton)findViewById(R.id.dtl_right);
	        dtlEnter.setOnClickListener(this);
	        dtlName = (Button)findViewById(R.id.dtl_change_name);
	        dtlName.setOnClickListener(this);
//	        btn_ok = (ImageButton)findViewById(R.id.rdl_ok);
//	        btn_ok.setMinimumWidth((Value.screenWidth) / 6);
//	        btn_ok.setMinimumHeight((Value.screenHeight) / 10);
//	        btn_ok.setOnClickListener(this);
	        mType = Value.rmtDev.getType();
	        tvName = (TextView) findViewById(R.id.dtl_name);
	        if (Value.rmtDev.getName()==null){
	        	  tvName.setText(getResources().getString(R.string.name));	
	        	  Value.rmtDev.setName(getResources().getString(R.string.name));
	        }else {
	        tvName.setText(Value.rmtDev.getName());
	        }
			listView=(ListView)findViewById(R.id.dtl_list); 
			listView.setOnItemClickListener(this);
		
			String[]	typeDevices = getResources().getStringArray(R.array.type_array);
			int[] typeChecks = {R.drawable.check_off,R.drawable.check_off,R.drawable.check_off,
					R.drawable.check_off,R.drawable.check_off,R.drawable.check_off		
			};
			     
//	            ArrayAdapter<String> adapter=new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1,typeDevices);
//	             listView.setAdapter(adapter);
			
			
			mContext = this;
			typeAdapter = new DeviceAdapter(mContext,typeDevices,typeChecks);
			listView.setAdapter(typeAdapter);
			typeAdapter.changeSelected(mType);
			
	    }
		@Override
		public void onClick(View v) {
			switch(v.getId()){
			case R.id.dtl_left:
				finish();
	    		break;
			case R.id.dtl_right:
				Intent i = new Intent(SelectDeviceType.this, SelectRemote.class);
				startActivity(i);
				finish();
				break;
			case R.id.dtl_change_name:
				Dialog dialog = new InputNameDialog(this, R.style.QuitDialog  ,new InputNameDialog.PriorityListener() {  

					@Override
					public void refreshDeviceName(String string) {
						// TODO Auto-generated method stub
						Value.rmtDev.setName(string);
					}  
		        });  
		          dialog.show();
				break;
	    	default:
	    		break;
			}
		}
		@Override
		public void onItemClick(AdapterView<?> av, View arg1, int position,
				long arg3) {
			// TODO Auto-generated method stub
				
			typeAdapter.changeSelected(position);
			Value.rmtDev.setType(position);
			Intent i = new Intent(SelectDeviceType.this, SelectRemote.class);
			startActivity(i);
			finish();
		}
}
