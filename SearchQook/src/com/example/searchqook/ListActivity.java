package com.example.searchqook;

import java.util.ArrayList;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ListView;

public class ListActivity extends Activity {
	ListView myListview;
	String key1 = "a868354ee2b5ee74ab78c84616a61480";
	String Data;
	int count = 6; //������ ������� 1���� ������ ���δ�.
	
	//CustomListAdapter adapter;
	//ArrayList<XmlData> m_xmlData;
	
	@Override
	protected void onCreate (Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		 myListview = (ListView) findViewById (R.id.myListview);
		 
		 Intent intent = getIntent();
		 Bundle myBundle = intent.getExtras();
		 Data = myBundle.getString("key"); //�˻��� ��������
		 
		 getNewList(Data,count); //ó�� 5�� ȭ��
		 
		 myListview.setOnItemClickListener(new OnItemClickListener() {
			 
				@Override
				public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
						long arg3) {
					// TODO Auto-generated method stub

					int Last = adapter.getCount();
					//adapter ��ü ���� ī����

					Log.i("NET", Last + "Parsing...");

					if ((Last - 1) == arg2) {
						count = count + 5;					
						getNewList(Data,count);							
						//�����⸦ Ŭ������ ��, ī���͸� 5 ������Ű�� GetNewList()
						
					} else
					{							
						String[] StringArrayData = StringArrayData(arg2);						
						Intent intent = new Intent (PriceListActivity.this,DetailActivity.class);						
						Bundle myData = new Bundle();										
						myData.putStringArray("key",StringArrayData);				
						intent.putExtras(myData);							
						startActivity(intent);						
					}
				}
			});
		}
	
	public void getNewList(String searchTxt , int NumberOfList) {		
		m_xmlData = naverPaser.GetXmlData(searchTxt, count);		
		adapter = new CustomListAdapter(this,R.layout.listitem,m_xmlData);
		myListview.setAdapter(adapter);		
	}
	
	public String[] StringArrayData(int arg2) {
		// TODO Auto-generated method stub
				
		XmlData xmlData = m_xmlData.get(arg2);
		
		String[] StringArrayData = new String[6];
		
		StringArrayData[0]=xmlData.d_title;
		StringArrayData[1]=xmlData.d_mallname;
		StringArrayData[2]=xmlData.d_link;
		StringArrayData[3]=xmlData.d_lprice;
		StringArrayData[4]=xmlData.d_hprice;
		StringArrayData[5]=xmlData.d_image;
		
		return StringArrayData ;
	}
	
	
}

