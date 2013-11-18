package com.deco.adapt;

import android.graphics.Bitmap;
import android.graphics.drawable.Drawable;

public class MenuList {


    private Bitmap menuBitmap;

 
    private String menuText;

    public MenuList(Bitmap menuBitmap, String menuText) {

        super();

        this.menuBitmap = menuBitmap;

        this.menuText = menuText;

    }

	

	public Bitmap getMenuBitmap() {
		return menuBitmap;
	}

	public void setMenuBitmap(Bitmap menuBitmap) {
		this.menuBitmap = menuBitmap;
	}

	public String getMenuText() {
		return menuText;
	}

	public void setMenuText(String menuText) {
		this.menuText = menuText;
	}

 


}
