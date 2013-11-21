package com.deco.remote;


import java.util.List;

import com.deco.adapt.RemoteAdapter;
import com.deco.adapt.RemoteAdapter.OnAdapterChangeListener;
import com.deco.allremote.R;
import com.deco.data.RemoteDevice;

import com.deco.data.Value;

import com.deco.ui.InputNameDialog;
import com.deco.utils.UserDB;




import android.app.Activity;

import android.app.Dialog;

import android.content.Intent;
import android.os.Bundle;

import android.util.Log;

import android.view.View;

import android.view.View.OnClickListener;
import android.widget.AdapterView;

import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.Toast;

import android.widget.AdapterView.OnItemClickListener;


public class RemoteDevicesList extends Activity implements OnClickListener,OnAdapterChangeListener,OnItemClickListener{
	ListView listView;
	ImageButton btn_add;

	ImageButton btn_cancel;
	List<RemoteDevice> list;
	RemoteAdapter rmtAdapter;
	public static RemoteDevicesList instance;
	enum LISTSTATUS {
	ADD,
	UPDATE,
	DELETE,
	};
	LISTSTATUS status = LISTSTATUS.ADD;
	int position;
	private ImageButton btn_bck;
    final static String TAG = "RemoteDevicesList";
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.remote_device_list);
        
        btn_add = (ImageButton)findViewById(R.id.rdl_right);
        btn_add.setOnClickListener(this);
        
        btn_bck = (ImageButton)findViewById(R.id.rdl_left);

        btn_bck.setOnClickListener(this);

        
        
		listView=(ListView)findViewById(R.id.remote_list); 
		listView.setCacheColorHint(0);
		listView.setOnItemClickListener(this);
	
//		list = Value.rmtDevs;
		instance=this;
		rmtAdapter = new RemoteAdapter(this, Value.rmtDevs);
    	
		rmtAdapter.setOnAdapterChangeListener(this);
		
		listView.setAdapter(rmtAdapter);
		
//		rmtAdapter = new RemoteAdapter(this, list);
//	
//		rmtAdapter.setOnAdapterChangeListener(this);
//		
//		listView.setAdapter(rmtAdapter);
    }
    @Override
    protected void onStart() {
    	// TODO Auto-generated method stub
    	super.onStart();
    	
    	
//		for (RemoteDevice rd :Value.rmtDevs){
//			Log.v(TAG, rd.getFullInfo());
//		}
//		Log.v(TAG, Value.rmtDev.getFullInfo());
    }
	@Override
	public void onClick(View v) {
		switch(v.getId()){
		case R.id.rdl_right:
			addDevice();
    		break;
		case R.id.rdl_left:
			//save();
			finish();
			break;
		
			
    	default:
    		break;
		}
	}
	
	
	@Override
	public void listRemove(int currentDevice) {
	
		rmtAdapter.notifyDataSetChanged();
		
	}
	
	private void addDevice(){
		if (Value.rmtDevs.size()<11){
		Value.rmtDev = new RemoteDevice();
		Dialog dialog = new InputNameDialog(this, R.style.QuitDialog  ,new InputNameDialog.PriorityListener() {  

			@Override
			public void refreshDeviceName(String string) {
				// TODO Auto-generated method stub
				Value.rmtDev.setName(string);
				Value.rmtDev.setId(Value.rmtDevs.size());
				Intent i = new Intent(RemoteDevicesList.instance, SelectDeviceType.class);
				RemoteDevicesList.instance.startActivity(i);
				Value.selectStatus = 1;
			}  
        });  
          dialog.show();
		}
	}
	

	
	@Override
	public void onItemClick(AdapterView<?> av, View arg1, int position, long arg3) {
		switch(av.getId()){
		case R.id.remote_list:
			Log.v(TAG, "remote"+(position+1)+"ok");
			this.position = position;
			status = LISTSTATUS.UPDATE;
			Value.rmtDev = (RemoteDevice) rmtAdapter.getItem(position);
			Intent i = new Intent(RemoteDevicesList.instance, SelectDeviceType.class);
			RemoteDevicesList.instance.startActivity(i);
			
			
//			Toast.makeText(MainActivity.this, "��ǰѡ�е�"+(position+1)+"��", Toast.LENGTH_LONG).show();
			break;
		default:
			break;
		}
		
	} 
	public void onActivityResult(int requestCode, int resultCode, Intent data) {
	
		 RemoteDevice device = new RemoteDevice();
		switch (requestCode) {
			case R.id.REQUEST_OPTIONS:
			 if (resultCode == RESULT_OK) {
			
				
				if(status==LISTSTATUS.ADD){
					int id = rmtAdapter.getCount();
					if (id<10){
					device = Value.rmtDev;
					device.setId(id);
					Log.v(TAG, "add id --->"+ Value.rmtDev.getInfo());
					
			//		RemoteGetKeyValue.remoteUpdateOrAddKeyValue(device,this,false);
					rmtAdapter.addItem(device);
					rmtAdapter.notifyDataSetChanged();
					}else {
					Toast.makeText(this, R.string.max_devices, Toast.LENGTH_LONG).show();	
					}
			
		        }else {
		        	int id = this.position;
		        	device = Value.rmtDev;
					device.setId(id);
					Log.v(TAG, "update id --->"+ id);
					
			//			RemoteGetKeyValue.remoteUpdateOrAddKeyValue(device,this,true);
						rmtAdapter.updateItem(device, id);
						rmtAdapter.notifyDataSetChanged();
						
			        }
			break;
			
	
			}

		}
	}
	   
	
}


