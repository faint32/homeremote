package com.deco.remote;


import java.util.List;

import com.deco.adapt.RemoteAdapter;
import com.deco.adapt.RemoteAdapter.OnAdapterChangeListener;
import com.deco.allremote.R;
import com.deco.data.RemoteDevice;
import com.deco.data.RemoteGetKeyValue;
import com.deco.data.Value;

import com.deco.ui.InputNameDialog;
import com.deco.utils.UserDB;



import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.Window;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.Toast;

import android.widget.AdapterView.OnItemClickListener;


public class RemoteDevicesList extends Activity implements OnClickListener,OnAdapterChangeListener,OnItemClickListener{
	ListView listView;
	Button btn_add;
	ImageButton btn_ok;
	ImageButton btn_cancel;
	List<RemoteDevice> list;
	RemoteAdapter rmtAdapter;
	enum LISTSTATUS {
	ADD,
	UPDATE,
	DELETE,
	};
	LISTSTATUS status = LISTSTATUS.ADD;
	int position;
    final static String TAG = "RemoteDevicesList";
	public static RemoteDevicesList mRmtListOpts;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.remote_device_list);
        
        btn_add = (Button)findViewById(R.id.rdl_add);
        btn_add.setOnClickListener(this);
        
        btn_ok = (ImageButton)findViewById(R.id.rdl_ok);
        btn_ok.setMinimumWidth((Value.screenWidth) / 6);
        btn_ok.setMinimumHeight((Value.screenHeight) / 10);
        btn_ok.setOnClickListener(this);

        
        
		listView=(ListView)findViewById(R.id.remote_list); 
		listView.setCacheColorHint(0);
		listView.setOnItemClickListener(this);
	
		list = Value.rmtDevs;
		mRmtListOpts=this;
		
		
		rmtAdapter = new RemoteAdapter(this, list);
	
		rmtAdapter.setOnAdapterChangeListener(this);
		
		listView.setAdapter(rmtAdapter);
    }
	@Override
	public void onClick(View v) {
		switch(v.getId()){
		case R.id.rdl_add:
			addDevice();
    		break;
		case R.id.rdl_ok:
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
		Value.rmtDev = new RemoteDevice();
		Dialog dialog = new InputNameDialog(this, R.style.QuitDialog  ,new InputNameDialog.PriorityListener() {  

			@Override
			public void refreshDeviceName(String string) {
				// TODO Auto-generated method stub
				Value.rmtDev.setName(string);
				Intent i = new Intent(RemoteDevicesList.mRmtListOpts, SelectRemote.class);
				RemoteDevicesList.mRmtListOpts.startActivityForResult(i, R.id.REQUEST_OPTIONS);
				status = LISTSTATUS.ADD;
			}  
        });  
          dialog.show();
		
	}
	

	
	@Override
	public void onItemClick(AdapterView<?> av, View arg1, int position, long arg3) {
		switch(av.getId()){
		case R.id.remote_list:
			Log.v(TAG, "remote"+(position+1)+"ok");
			this.position = position;
			status = LISTSTATUS.UPDATE;
			Value.rmtDev = (RemoteDevice) rmtAdapter.getItem(position);
			Intent i = new Intent(RemoteDevicesList.mRmtListOpts, SelectRemote.class);
			RemoteDevicesList.mRmtListOpts.startActivityForResult(i, R.id.REQUEST_OPTIONS);
			
			
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
					
					RemoteGetKeyValue.remoteUpdateOrAddKeyValue(device,this,false);
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
					
						RemoteGetKeyValue.remoteUpdateOrAddKeyValue(device,this,true);
						rmtAdapter.updateItem(device, id);
						rmtAdapter.notifyDataSetChanged();
						
			        }
			break;
			
	
			}

		}
	}
	   
	
}

