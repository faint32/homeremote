package com.sommer.remote;

import java.util.ArrayList;
import java.util.List;

import com.sommer.allremote.R;
import com.sommer.data.RemoteList;
import com.sommer.ui.RemoteAdapter;
import com.sommer.ui.RemoteAdapter.OnAdapterChangeListener;



import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;
import android.widget.AdapterView.OnItemClickListener;


public class RemoteListOptions extends Activity implements OnClickListener,OnAdapterChangeListener,OnItemClickListener{
	ListView listView;
	Button btn_add;
	List<RemoteList> list;
	RemoteAdapter numberAdapter;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.remote_list_options);
        btn_add = (Button)findViewById(R.id.btn_add);
        btn_add.setOnClickListener(this);
		listView=(ListView)findViewById(R.id.remote_list); 

		listView.setCacheColorHint(0);

		listView.setOnItemClickListener(this);
	
		list = new ArrayList<RemoteList>();
		RemoteList item = new RemoteList();

		item.setName("1");
		list.add(item);
		

		
		
		numberAdapter = new RemoteAdapter(this, list);
	
		numberAdapter.setOnAdapterChangeListener(this);
		
		listView.setAdapter(numberAdapter);
    }
	@Override
	public void onClick(View v) {
		switch(v.getId()){
		case R.id.btn_add:
    		addItem();
    		break;
    	default:
    		break;
		}
	}
	
	
	@Override
	public void listRemove(int currentItem) {
	
		numberAdapter.notifyDataSetChanged();
		
	}
	
	private void addItem(){
		RemoteList item = new RemoteList();
		item.setType(1);
		item.setName("home");
		numberAdapter.addItem(item);
		
		numberAdapter.notifyDataSetChanged();
		
		
	}
	
	
	@Override
	public void onItemClick(AdapterView<?> av, View arg1, int position, long arg3) {
		switch(av.getId()){
		case R.id.remote_list:
			Alert(RemoteListOptions.this, "remote"+(position+1)+"ok");
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