package com.sommer.remote;


import java.util.List;

import com.sommer.allremote.R;
import com.sommer.data.RemoteDevice;
import com.sommer.data.Value;
import com.sommer.ui.RemoteAdapter;
import com.sommer.ui.RemoteAdapter.OnAdapterChangeListener;



import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
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
    final static String TAG = "RemoteDevicesList";
	public static RemoteDevicesList mRmtListOpts;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.remote_device_list);
        
        btn_add = (Button)findViewById(R.id.rdl_add);
        btn_add.setOnClickListener(this);
        btn_ok = (ImageButton)findViewById(R.id.rdl_ok);
        btn_ok.setOnClickListener(this);
        
        btn_cancel = (ImageButton)findViewById(R.id.rdl_cancel);
        btn_cancel.setOnClickListener(this);
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
		case R.id.rdl_cancel:
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
		
		Intent i = new Intent(RemoteDevicesList.mRmtListOpts, SelectRemote.class);
		RemoteDevicesList.mRmtListOpts.startActivityForResult(i, R.id.REQUEST_OPTIONS);
		
		
		
	}
	
	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		 Bundle bundle; 
		switch (requestCode) {
		case R.id.REQUEST_OPTIONS:
			 if (resultCode == RESULT_OK) {
				 bundle = data.getExtras(); 
				 int id = rmtAdapter.getCount();
				 RemoteDevice device = new RemoteDevice();
				    device.setId(id);
					device.setType(bundle.getInt("type"));
					device.setName(bundle.getString("name"));
					device.setBrand(bundle.getString("brand"));
					device.setCode(bundle.getString("index") );
					Log.v(TAG, "id --->"+ id);
				rmtAdapter.addItem(device);
				rmtAdapter.notifyDataSetChanged();
		        }
			break;
		default:
			break;
		}

	}

	
	@Override
	public void onItemClick(AdapterView<?> av, View arg1, int position, long arg3) {
		switch(av.getId()){
		case R.id.remote_list:
			Log.v(TAG, "remote"+(position+1)+"ok");
			Alert(RemoteDevicesList.this, "remote"+(position+1)+"ok");
//			Toast.makeText(MainActivity.this, "��ǰѡ�е�"+(position+1)+"��", Toast.LENGTH_LONG).show();
			break;
		default:
			break;
		}
		
	} 
	public static void Alert(Context context,String error) {
		AlertDialog.Builder builder = new AlertDialog.Builder(context);
		builder.setMessage(error)
        //.setTitle(R.string.dialog_value_sys_title)
        //.setIcon(R.drawable.dialog_icon)
         .setCancelable(false)
        .setPositiveButton("remote", new DialogInterface.OnClickListener() {
         public void onClick(DialogInterface dialog, int id) {
      	   dialog.cancel();
         }
     });
		 builder.show();
	}
	
}