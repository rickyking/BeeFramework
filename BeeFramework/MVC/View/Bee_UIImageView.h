//
//	 ______    ______    ______    
//	/\  __ \  /\  ___\  /\  ___\   
//	\ \  __<  \ \  __\_ \ \  __\_ 
//	 \ \_____\ \ \_____\ \ \_____\ 
//	  \/_____/  \/_____/  \/_____/ 
//
//	Copyright (c) 2012 BEE creators
//	http://www.whatsbug.com
//
//	Permission is hereby granted, free of charge, to any person obtaining a
//	copy of this software and associated documentation files (the "Software"),
//	to deal in the Software without restriction, including without limitation
//	the rights to use, copy, modify, merge, publish, distribute, sublicense,
//	and/or sell copies of the Software, and to permit persons to whom the
//	Software is furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//	IN THE SOFTWARE.
//
//
//  Bee_UIImageView.h
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Bee_Cache.h"
#import "Bee_Network.h"
#import "Bee_UISignal.h"

#pragma mark -

@interface BeeImageCache : NSObject
{
	BeeMemoryCache *	_memoryCache;
	BeeFileCache *		_fileCache;
}

AS_SINGLETON( BeeImageCache )

- (BOOL)hasCachedForURL:(NSString *)url;
- (UIImage *)imageForURL:(NSString *)url;

- (void)saveImage:(UIImage *)image forURL:(NSString *)url;
- (void)saveData:(NSData *)data forURL:(NSString *)url;
- (void)deleteImageForURL:(NSString *)url;
- (void)deleteAllImages;

@end

#pragma mark -

@class BeeUIActivityIndicatorView;

@interface BeeUIImageView : UIImageView
{
	BOOL							_gray;
	BOOL							_rounded;
	BOOL							_loading;
	BeeUIActivityIndicatorView *	_indicator;
	NSString *						_loadedURL;
	BOOL							_loaded;	
}

AS_SIGNAL( LOAD_START )			// 加载开始
AS_SIGNAL( LOAD_COMPLETED )		// 加载完成
AS_SIGNAL( LOAD_FAILED )		// 加载失败
AS_SIGNAL( LOAD_CANCELLED )		// 加载取消

@property (nonatomic, assign) BOOL							gray;	// 是否变为灰色
@property (nonatomic, assign) BOOL							rounded;		// 是否裁剪为圆型
@property (nonatomic, assign) BOOL							loading;
@property (nonatomic, assign) BOOL							loaded;
@property (nonatomic, retain) BeeUIActivityIndicatorView *	indicator;
@property (nonatomic, retain) NSString *					loadedURL;

@property (nonatomic, assign) NSString *					url;
@property (nonatomic, assign) NSString *					file;
@property (nonatomic, assign) NSString *					resource;

+ (BeeUIImageView *)spawn;

- (void)GET:(NSString *)url useCache:(BOOL)useCache;
- (void)GET:(NSString *)url useCache:(BOOL)useCache placeHolder:(UIImage *)defaultImage;

- (void)clear;

@end
