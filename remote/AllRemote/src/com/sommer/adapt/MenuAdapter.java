package com.sommer.adapt;

import java.util.List;

import com.sommer.allremote.R;



import android.app.Activity;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import android.widget.BaseAdapter;

import android.widget.ImageView;

import android.widget.TextView;




public class MenuAdapter extends BaseAdapter {

    private Activity context;

    private List<MenuList> list;

 

    public MenuAdapter(Activity context, List<MenuList> list) {

        this.context = context;

        this.list = list;

    }

 

    @Override

    public View getView(int position, View convertView, ViewGroup parent) {

        LayoutInflater inflater = context.getLayoutInflater();

        View itemView = inflater.inflate(R.layout.adapter_menu_item, null);

        MenuList ml = list.get(position);

        TextView textView = (TextView) itemView.findViewById(R.id.menu_name);

        ImageView imageView = (ImageView) itemView

                .findViewById(R.id.menu_pics);

        textView.setText(ml.getMenuText());

        imageView.setImageBitmap(ml.getMenuBitmap());

        return itemView;

    }

 

    @Override

    public int getCount() {

        return list.size();

    }

 

    @Override

    public Object getItem(int position) {

        return list.get(position);

    }

 

    @Override

    public long getItemId(int position) {

        return position;

    }

}
