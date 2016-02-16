//
//  FileSelectorBundle.h
//  FileSelectorBundle
//
//  Created by rossyang on 15/9/11.
//
//

#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>
//! Project version number for FileSelectorBundle.
FOUNDATION_EXPORT double FileSelectorBundleVersionNumber;

//! Project version string for FileSelectorBundle.
FOUNDATION_EXPORT const unsigned char FileSelectorBundleVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FileSelectorBundle/PublicHeader.h>


@interface FileSelectorBundle : NSObject

//文件选择
- (void)fileSelector:(NSDictionary *)param withHandler:(void(^)(NSDictionary *result)) handler;
- (void)fileSelectorForJS:(NSDictionary *)param :(JSValue *)callBack;

//图片选择
- (void)picSelector:(NSDictionary *)param withHandler:(void(^)(NSDictionary *result)) handler;
- (void)picSelectorForJS:(NSDictionary *)param :(JSValue*)callback;
@end