#include "Textures.h"

#include "Filer.h"
#include "GUI.h"

//#include "jmsf/stdal/stdal_stl.h"


// CTexture *Texture;
// TextureImage global_Textures[TEX_TYPES];
::sf::Texture *global_Textures[ TEX_TYPES ]; // = {};

::sf::Image LoadTextureWithAlphaFromFile( ::std::string const path_to_texture_file ) {
	::sf::Image loadedImage;
	loadedImage.loadFromFile( "textures\\missile.png" );
	::sf::Vector2u const loadedImageSize = loadedImage.getSize();
	::sf::Image alphaAppliedImage;
	alphaAppliedImage.create( loadedImageSize.x, loadedImageSize.y );
	alphaAppliedImage.copy( loadedImage, 0, 0, ::sf::IntRect( 0, 0, loadedImageSize.x, loadedImageSize.y ), true );
	return alphaAppliedImage;
}

bool LoadGLTextures()
{
//	Texture->LoadTexture( "textures\\cursor.png", &global_Textures[ 0 ], 0 );
//	Texture->LoadTexture( "textures\\missile.png", &global_Textures[ 1 ], 1 );
//	Texture->LoadTexture( "textures\\states.png", &global_Textures[ 2 ], 0 );
//	Texture->LoadTexture( "textures\\wid.png", &global_Textures[ 3 ], 0 );
//	Texture->LoadTexture( "textures\\digits.png", &global_Textures[ 4 ], 0 );
//	Texture->LoadTexture( "textures\\arial_font.png", &global_Textures[ 5 ], 0 );
//	Texture->LoadTexture( "textures\\attack_cursor.png", &global_Textures[ 6 ], 0 );
//	Texture->LoadTexture( "textures\\frame1.png", &global_Textures[ 7 ], 0 );
//	Texture->LoadTexture( "textures\\frame2.png",&global_Textures[ 8 ], 0 );
//	Texture->LoadTexture( "textures\\frame3.png", &global_Textures[ 9 ], 0 );

//	Texture->LoadTexture( "textures\\Units.png", &global_Textures[ 10 ], 1 );
//	Texture->LoadTexture( "textures\\Bases.png", &global_Textures[ 11 ], 1 );
//	Texture->LoadTexture( "textures\\bg2.jpg", &global_Textures[ 12 ], 1 );


//	Texture->LoadTexture( "textures\\p1.tga", &global_Textures[ 13 ], 1 );
//	Texture->LoadTexture( "textures\\p2.tga", &global_Textures[ 14 ], 1 );
//	Texture->LoadTexture( "textures\\p3.tga", &global_Textures[ 15 ], 1 );
//	Texture->LoadTexture( "textures\\p4.tga", &global_Textures[ 16 ], 1 );
//	Texture->LoadTexture( "textures\\p5.tga", &global_Textures[ 17 ], 1 );
//	Texture->LoadTexture( "textures\\p6.tga", &global_Textures[ 18 ], 1 );
//	Texture->LoadTexture( "textures\\p7.tga", &global_Textures[ 19 ], 1 );
//	Texture->LoadTexture( "textures\\p8.tga", &global_Textures[ 20 ], 1 );

//	Texture->LoadTexture( "textures\\anim.png", &global_Textures[ 21 ], 1 );

	global_init_textures();

	bool have_been_all_textures_loaded = true;

	::sf::Texture *the_texture_0 = global_Textures[ 0 ];

	if ( the_texture_0 == nullptr ) return false;

	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 0 ]->loadFromFile( "textures\\cursor.png" ) ;

	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 1 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\missile.png" ) );


	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 2 ]->loadFromFile( "textures\\states.png" );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 3 ]->loadFromFile( "textures\\wid.png" );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 4 ]->loadFromFile( "textures\\digits.png" );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 5 ]->loadFromFile( "textures\\arial_font.png" );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 6 ]->loadFromFile( "textures\\attack_cursor.png" );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 7 ]->loadFromFile( "textures\\frame1.png" );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 8 ]->loadFromFile( "textures\\frame2.png" );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 9 ]->loadFromFile( "textures\\frame3.png" );

	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 10 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\Units.png" ) );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 11 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\Bases.png" ) );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 12 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\bg2.jpg" ) );


	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 13 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\p1.tga" ) );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 14 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\p2.tga" ) );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 15 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\p3.tga" ) );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 16 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\p4.tga" ) );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 17 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\p5.tga" ) );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 18 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\p6.tga" ) );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 19 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\p7.tga" ) );
	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 20 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\p8.tga" ) );

	have_been_all_textures_loaded = !have_been_all_textures_loaded ? false : global_Textures[ 21 ]->loadFromImage( LoadTextureWithAlphaFromFile( "textures\\anim.png" ) );

	if ( !have_been_all_textures_loaded ) return false;


	CFile f1;

	if ( !f1.Open( "arial_font", OPEN_EXISTING ) ) {
		return false;
	}

	f1.Read( ArialFont.ch, 224 * sizeof( FontChar ) );
	ArialFont.txt = &( TEXTURE_ARIAL_FONT );
	f1.Close();

	return true;
}

//void MultAlpha( TextureImage *txt )
//{
////	unsigned i,j;
////	double koef;

//	if ( txt->bpp != 4 ) return;

//	for ( size_t i = 0; i < txt->height * txt->width; i++ ) {
//		double const koef = txt->imageData[ 4 * i + 3 ] / 255.0;

//		for ( size_t j = 0; j < 3; j++ ) {
//			txt->imageData[ 4 * i + j ] = ( GLubyte )( txt->imageData[ 4 * i ] * koef );
//		}
//	}
//}

//CTexture::CTexture()
//{
//	// В конструкторе инициализируем библиотеки IL и ILU.
//	// Если этого не сделать, программа будет вываливатся с ошибкой.
//	ilInit();
//	iluInit();
//}

//// Деструктор
//CTexture::~CTexture()
//{
//}

//// Функция, непосредственно загружающая текстуру в переданную структуру.
//// В функцию передается тип файла, имя файла и указатель на текстуру.
//// void CTexture::LoadTexture(ILenum FileType, char *filename, TextureImage *texture, const bool bMultAlpha)
//void CTexture::LoadTexture( char const *const filename, ::sf::Texture *texture, bool const bMultAlpha ) {
//	// Просим DevIL загрузить файл
//	::ilLoad( FileType, std::toWideString( filename ).c_str() );

//	// Проверяем, нет ли ошибок при открытии файла
//	int err=::ilGetError();
//	if(err!=IL_NO_ERROR)
//	{
//		const wchar_t *strError = ::iluErrorString( err );
//		MessageBox(NULL, strError, L"Ошибка при загрузке!", MB_OK);
//		exit(1);
//	}


//	// Получаем данные текстуры
//	texture->width = ilGetInteger(IL_IMAGE_WIDTH);			// Ширина
//	texture->height = ilGetInteger(IL_IMAGE_HEIGHT);		// Высота
//	texture->bpp = ilGetInteger(IL_IMAGE_BYTES_PER_PIXEL);		// Байт на пиксель

//	// Загружаем данные в нашу текстуру
//	texture->imageData = ilGetData();

//	ilEnable(IL_CONV_PAL);

//	// Тип данных изображения
//	unsigned int type = ilGetInteger(IL_IMAGE_FORMAT);

//	if ( !texture->loadFromFile( filename ) ) {
//		MessageBox(NULL, strError, L"Ошибка при загрузке!", MB_OK);
//		exit( 1 );
//	}


//	// Генерируем текстуру
//	glGenTextures(1, &texture->texID);

//	// Привязываем данные текстуры к ID
//	glBindTexture(GL_TEXTURE_2D,texture->texID);

//	if ( bMultAlpha ) {
//		MultAlpha( texture );
//	}

//	// биндим мип-мапы
//	gluBuild2DMipmaps(GL_TEXTURE_2D, texture->bpp, texture->width,
//		texture->height, type, GL_UNSIGNED_BYTE, texture->imageData);

//	// Устанавливаем качество текстур
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//}

//void CTexture::FreeTexture(TextureImage *texture)
//{

//}

void global_init_textures() {
	for ( size_t texture_index = 0; texture_index < TEX_TYPES; ++texture_index ) {
		global_Textures[ texture_index ] = new ::sf::Texture;
	}
}

void global_reset_textures() {
	for ( size_t texture_index = 0; texture_index < TEX_TYPES; ++texture_index ) {
		delete global_Textures[ texture_index ];
		global_Textures[ texture_index ] = nullptr;
	}
}
