
// 数値列の読み込み

// 201709/21 新規作成


// グローバル変数設定
boolean sDone = false;
long inlong;

#define LED 13


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
	//serialEvent();
	if ( sDone ) 
	{
		digitalWrite ( LED, 1 );
		Serial.println ( inlong * 10 );
		sDone = false;          // 受信待ちフラグ
		inlong = 0;
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

