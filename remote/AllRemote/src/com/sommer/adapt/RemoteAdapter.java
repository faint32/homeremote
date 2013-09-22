package com.sommer.adapt;

import java.util.List;

import com.sommer.allremote.R;
import com.sommer.data.RemoteDevice;
import com.sommer.data.Value;
import com.sommer.remote.RemoteDevicesList;
import com.sommer.remote.Start;
import com.sommer.remote.StudyActivity;
import com.sommer.remote.TVRemote;
import com.sommer.utils.UserDB;


import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;



public class RemoteAdapter extends BaseAdapter {
	private List<RemoteDevice> list;
	private LayoutInflater inflater;

	private Context context;
	private OnAdapterChangeListener listener;
	
	public RemoteAdapter(Context context, List<RemoteDevice> items) {
		this.list = items;
		this.context = context;

		inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);	

	}
	
	public void setOnAdapterChangeListener(OnAdapterChangeListener listener){    
		this.listener = listener;
    }
	/**
	 * 获取数据集长度
	 */
	@Override
	public int getCount() {
		return list.size();
	}

	/**
	 * 根据位置获取当前数据
	 */
	@Override
	public Object getItem(int position) {
		return list.get(position);
	}
	
	/**
	 * 获取位置
	 */
	@Override
	public long getItemId(int position) {
		return position;
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		ViewHolder holder = null;	
		if (convertView == null) {
			//获取布局文件
			convertView = inflater.inflate(R.layout.adapter_list_item, null);
			//new一个对象，存放每条item的窗体
			holder = new ViewHolder();

			//获取输入框控件
			holder.info = (TextView)convertView.findViewById(R.id.remote_info);
			//将当前位置放入到tag中
			holder.info.setTag(position);
			//设置输入框数据发生变化的监听事件
//			holder.info.addTextChangedListener(new MyTextWatcher(holder){
//
//				@Override
//				public void afterTextChanged(Editable s, ViewHolder holder) {
//					int p = (Integer)holder.info.getTag();
//						modifyListname(s.toString(),p);
//				}
//
//			});
			//获取按钮
			holder.cancel = (Button)convertView.findViewById(R.id.remote_delete);
			//添加按钮事件
			holder.cancel.setOnClickListener(new MyOnClickListener(holder){

				@Override
				public void onClick(View v, ViewHolder holder) {

					if(list.size()>1){
						int p = (Integer)holder.info.getTag();
						UserDB mUsrDB = new UserDB(context);
						mUsrDB.open();
						RemoteDevice rmtDev = list.get(p);
						Boolean isSmart = false;
						if (rmtDev.getType()==Value.DeviceType.TYPE_AIR)
						{
							isSmart = true;
						}
						mUsrDB.deleteRemoteDevice(isSmart,p);
						mUsrDB.close();	
						list.remove(p);
						if(listener!=null){
							listener.listRemove(p);
						}
						
					}
				}});
			
		
			
			
			//获取文本控件
			holder.id =  (TextView)convertView.findViewById(R.id.remote_id);
			//将每条Item的控件对象放入tag中
			convertView.setTag(holder);
			
		}else{
			holder = (ViewHolder)convertView.getTag();
			holder.info.setTag(position);
		}
		
		
		
		RemoteDevice rmtDev = list.get(position);
		 holder.id.setText(position+1+"");
		 holder.info.setText(rmtDev.getInfo());
	//	 holder.type.setAdapter(adapter);  
	//	 int p = getPositionForAdapter(position);
	//	 holder.type.setSelection(p, true);
		 return convertView;
	}
	
	

	public void addItem(RemoteDevice rmtDev){
		list.add(rmtDev);
	}
	public void updateItem(RemoteDevice rmtDev,int id){
		list.set(id,rmtDev);
	}
	
	public List<RemoteDevice> getAllList(){
		return list;
	}
	

	

	 private final class ViewHolder{         
  
	    	private TextView info;   
	    	private Button cancel;   
	    	private TextView id;
	   
	 }
	 

	 private abstract class MyOnClickListener implements View.OnClickListener{
		 
		 private ViewHolder mViewHolder;
		 public MyOnClickListener(ViewHolder viewHolder) {
				mViewHolder = viewHolder;
		 }
		@Override
		public void onClick(View v) {
			onClick(v,mViewHolder);
			
		}
		public abstract void onClick(View v,ViewHolder viewHolder); 
		 
	 }

	
	 public interface OnAdapterChangeListener {
		
			public void listRemove(int currentItem);  
	 }
}
