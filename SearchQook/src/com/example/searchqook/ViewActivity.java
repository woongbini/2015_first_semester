package com.example.searchqook;

import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;

public class ViewActivity extends Activity{
	private WebView mWebview;
	
	@Override
	public void onCreate (Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_view);
		
		setLayout();
		
		//웹뷰에서 자바스크립트 실행가능
		mWebview.getSettings().setJavaScriptEnabled(true);
		//웹뷰클라이언트 지정
		mWebview.setWebViewClient(new WebViewClientClass());
	}
	
	 @Override
	    public boolean onKeyDown(int keyCode, KeyEvent event) { 
	        if ((keyCode == KeyEvent.KEYCODE_BACK) && mWebview.canGoBack()) { 
	            mWebview.goBack(); 
	            return true; 
	        } 
	        return super.onKeyDown(keyCode, event);
	    }
	     
	    private class WebViewClientClass extends WebViewClient { 
	        @Override
	        public boolean shouldOverrideUrlLoading(WebView view, String url) { 
	            view.loadUrl(url); 
	            return true; 
	        } 
	    }
		
		
		

	private void setLayout(){
        mWebview = (WebView) findViewById(R.id.webview);
    }


}
