package com.sommer.adapt;

import com.sommer.allremote.R;

import android.content.Context;
import android.graphics.Color;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class DeviceAdapter extends BaseAdapter {
	 String textstr[];
	 int picid[];
	 int length;
	 Context context;
	 LayoutInflater inflater;;
	 int selectedposition=0;
	 int color=0;
	public DeviceAdapter(Context c,String[] text,int[] pic){
	 length=text.length;
	 textstr=text;
	 picid=pic;
	 context=c;
	 inflater=LayoutInflater.from(context);
	}
	 @Override
	 public int getCount() {
	  // TODO Auto-generated method stub
	  return length;
	 }
	 @Override
	 public Object getItem(int position) {
	  // TODO Auto-generated method stub
	  return textstr[position];
	 }
	public void setPositionSelected(int position){
	 selectedposition=position;
	}
	 @Override
	 public long getItemId(int position) {
	  // TODO Auto-generated method stub
	  return position;
	 }
	 @Override
	 public View getDropDownView(int position, View convertView, ViewGroup parent) {
	  // TODO Auto-generated method stub
	  
	  if(convertView==null){
	   convertView=inflater.inflate(R.layout.option_device, null);
	  }
	  Log.v("menu", "position: "+position+" selectedposition :"+selectedposition);
	 
	  ImageView image=(ImageView)convertView.findViewById(R.id.device_select);
	  TextView text=(TextView)convertView.findViewById(R.id.device_name);
	  image.setImageResource(picid[position]);
	  text.setText(textstr[position]);
	  if(selectedposition==position){
		  image.setImageResource(R.drawable.check_on);
		  }else{
			  image.setImageResource(R.drawable.check_off);
		   
		  }
	  
	  
	  return super.getDropDownView(position, convertView, parent);
	 }
	 @Override
	 public View getView(int position, View convertView, ViewGroup parent) {
	  if(convertView==null){
	   convertView=inflater.inflate(R.layout.option_device, null);
	  }
	  
	  ImageView image=(ImageView)convertView.findViewById(R.id.device_select);
	  TextView text=(TextView)convertView.findViewById(R.id.device_name);
	  image.setImageResource(picid[position]);
	  text.setText(textstr[position]);
	  if(selectedposition==position){
		  image.setImageResource(R.drawable.check_on);
		  }else{
			  image.setImageResource(R.drawable.check_off);
		   
		  }
	  return convertView;
	 }
	 
	 public void changeSelected(int positon){
		  if(positon != selectedposition){
		 selectedposition = positon;
		   notifyDataSetChanged();
		  }
	 }
	
	
	}