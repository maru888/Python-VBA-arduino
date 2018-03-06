
// データロガーのサンプル

// 201709/22 新規作成


// グローバル変数設定
boolean sDone = false;
long inlong;
long indata[10];
int mode;

#define LED 13

int para_count;

// セットアップ
void setup()
{
	pinMode ( LED, OUTPUT );
	Serial.begin ( 115200 );   // シリアル通信速度設定
	digitalWrite ( LED, 0 );
}


// メイン関数
void loop()
{	
	int j;
	int num_data;
	int fst_data;
	int add_data;
	int num_counter = 0;
	
	if ( sDone ) 
	{
		if ( mode == 0 )
		{
			// スタート信号受信
			if ( inlong == 999 )
			{
				mode = 1;
				Serial.println ( inlong );
				digitalWrite ( LED, 1 );
				sDone = false;          // 受信待ちフラグ
				inlong = 0;
			}
		}
		else if ( mode == 1 )
		{
			// パラメータ受信
			indata[para_count] = inlong;
			Serial.println ( indata[para_count] );
			digitalWrite ( LED, 0 );

			++ para_count;
			sDone = false;          // 受信待ちフラグ
			inlong = 0;

			if ( para_count > 2 )
			{
				mode = 2;
			}
		}
	}
	if ( mode == 2 )
	{
		// データ出力
		num_data = indata[0];
		fst_data = indata[1];
		add_data = indata[2];
		
		for ( j = fst_data ; num_counter < num_data ; j = j + add_data)
		{
			Serial.println ( j );
			++ num_counter;
		}		
		while(1);
	}
}


// シリアル受信
void serialEvent()
{
	char inbyte;

	while ( Serial.available() )
	{
		inbyte = Serial.read();

		if ( inbyte == '\n' )
		{
			sDone = true;
		}
		else
		{
			inlong = ( inlong * 10 ) + ( inbyte - 0x30 );
		}
	}
}

