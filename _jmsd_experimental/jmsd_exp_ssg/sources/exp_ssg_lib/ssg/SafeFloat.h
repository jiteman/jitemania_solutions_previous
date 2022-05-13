#pragma once


extern char *game_content;

class Pocket;


int SafeGame( bool replace_float, int greed_val );
void SendGameContent();
void RecvGameContent();
void PackGameContent( Pocket &pc );
void UnPackGameContent( Pocket &pc );
