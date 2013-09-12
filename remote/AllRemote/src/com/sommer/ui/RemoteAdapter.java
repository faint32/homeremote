package com.sommer.ui;

import java.util.List;

import com.sommer.allremote.R;
import com.sommer.data.RemoteDevice;


import android.content.Context;
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
	private ArrayAdapter<CharSequence> adapter;
	private static  String[] SPINNER_REMOTE_TYPE;
	private Context context;
	private OnAdapterChangeListener listener;
	
	public RemoteAdapter(Context context, List<RemoteDevice> items) {
		this.list = items;
		this.context = context;
		SPINNER_REMOTE_TYPE = context.getResources().getStringArray(R.array.type_array);
		inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);	
		//下拉框的数据适配器
//		adapter = new ArrayAdapter<String>(context,android.R.layout.simple_spinner_item,SPINNER_REMOTE_TYPE);
//		adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
		
		 adapter = ArrayAdapter.createFromResource(
				 context, R.array.type_array,
	                android.R.layout.simple_spinner_item);
		 adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
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
			convertView = inflater.inflate(R.layout.adapter_remotelist_item, null);
			//new一个对象，存放每条item的窗体
			holder = new ViewHolder();
			
			//下拉框控件
			holder.type = (Spinner)convertView.findViewById(R.id.remote_type);
			//设置数据选择的事件
			holder.type.setOnItemSelectedListener(new  MySpinnerListener(holder){
				@Override
				public void onNothingSelected(AdapterView<?> arg0) {
					
				}

				@Override
				public void onItemSelected(AdapterView<?> arg0, View arg1,
						int arg2, long arg3, ViewHolder viewHolder) {
					TextView tv = (TextView)arg1;
					int p = (Integer)viewHolder.name.getTag();
					modifyListType(tv.getText().toString(),p);
					
				}} );
			//获取输入框控件
			holder.name = (EditText)convertView.findViewById(R.id.remote_name);
			//将当前位置放入到tag中
			holder.name.setTag(position);
			//设置输入框数据发生变化的监听事件
			holder.name.addTextChangedListener(new MyTextWatcher(holder){

				@Override
				public void afterTextChanged(Editable s, ViewHolder holder) {
					int p = (Integer)holder.name.getTag();
						modifyListname(s.toString(),p);
				}

			});
			//获取按钮
			holder.cancel = (Button)convertView.findViewById(R.id.remote_delete);
			//添加按钮事件
			holder.cancel.setOnClickListener(new MyOnClickListener(holder){

				@Override
				public void onClick(View v, ViewHolder holder) {
//					int p = (Integer)holder.name.getTag();
//					Toast.makeText(context, "当前是第"+p+"条", Toast.LENGTH_LONG).show();
					if(list.size()>1){
						int p = (Integer)holder.name.getTag();
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
			holder.name.setTag(position);
		}
		
		
		
		RemoteDevice rmtDev = list.get(position);
		 holder.id.setText(position+1+"");
		 holder.name.setText(rmtDev.getName());
		 holder.type.setAdapter(adapter);  
		 int p = getPositionForAdapter(position);
		 holder.type.setSelection(p, true);
		 return convertView;
	}
	
	

	public void addItem(RemoteDevice rmtDev){
		list.add(rmtDev);
	}
	
	public List<RemoteDevice> getAllList(){
		return list;
	}
	
	
	private int getPositionForAdapter(int po){
		
		RemoteDevice  t = list.get(po);
		int p = 0;
		for(int i=0;i<SPINNER_REMOTE_TYPE.length;i++){
//			if(t.getType().equal(SPINNER_TIME[i])){
//				p = i;
//			}
		}
		return p;
	}
	
	
	private void modifyListType(String type,int p){
		if(p>=list.size()) return;
		RemoteDevice  t = list.get(p);
	//	t.setType(type);
		list.set(p, t);
		
	}
	
	
	private void modifyListname(String name ,int p){
		if(p>=list.size()) return;
		RemoteDevice  t = list.get(p);
		t.setName(name);
		list.set(p, t);
	}
	
	 private final class ViewHolder{         
	    	private Spinner type;      
	    	private EditText name;   
	    	private Button cancel;   
	    	private TextView id;
	    	private TextView attr;
	    	private Button index;
	 }
	 
	 private abstract class MySpinnerListener implements AdapterView.OnItemSelectedListener{
		 private ViewHolder mViewHolder;

			public MySpinnerListener(ViewHolder holder) {
				mViewHolder = holder;
				}
			
			@Override
			public void onItemSelected(AdapterView<?> arg0, View arg1,
					int arg2, long arg3) {
				onItemSelected (arg0,  arg1,
						arg2,  arg3,mViewHolder);
				
			}

			@Override
			public void onNothingSelected(AdapterView<?> arg0) {
				
			}

			public abstract void onItemSelected(AdapterView<?> arg0, View arg1,
					int arg2, long arg3,ViewHolder viewHolder);


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
	 private abstract class MyTextWatcher implements TextWatcher{
		 private ViewHolder mViewHolder;
		 public MyTextWatcher(ViewHolder holder) {
				mViewHolder= holder;
		 }
		@Override
		public void afterTextChanged(Editable s) {
			afterTextChanged(s,mViewHolder);
		}
		
		@Override
		public void beforeTextChanged(CharSequence s, int start, int count,
				int after) {
			
		}
		@Override
		public void onTextChanged(CharSequence s, int start, int before,
				int count) {
			
		}
		public abstract void  afterTextChanged(Editable s,ViewHolder holder);
		
	 }
	 
	
	 public interface OnAdapterChangeListener {
		
			public void listRemove(int currentItem);  
	 }
}
