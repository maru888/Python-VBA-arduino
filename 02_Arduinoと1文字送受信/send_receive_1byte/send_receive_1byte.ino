
// 1バイト文字列の送受信プログラム

// 2017/09/21 新規作成



#define LED 13



void setup()
{
	pinMode ( LED, OUTPUT ); //13番ピンを出力に設定

	Serial.begin ( 115200 ); //シリアル通信のレートを9600に設定
}



void loop()
{
	int i;

	// 受信
	if ( Serial.available() )
	{
		byte inbyte = Serial.read();
		int inint = inbyte - 0x30;
		
		if ( inint >= 0 )
		{
			if ( inint == 0 )
			{
				digitalWrite ( LED, 0 );
			}
			else if ( inint == 1 )
			{
				digitalWrite ( LED, 1 );
			}
			else
			{
				for ( i = 0; i < inint; ++i )
				{
					digitalWrite ( LED, 1 );
					delay ( 50 );
					digitalWrite ( LED, 0 );
					delay ( 150 );
				}
			}

			// 返信
			Serial.println ( inint );
		}
	}
}
