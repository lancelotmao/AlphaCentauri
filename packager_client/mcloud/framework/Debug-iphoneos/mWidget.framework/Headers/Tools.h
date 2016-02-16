//
//  bTools.h
//  mWidget
//
//  Created by Nil on 13/10/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "MRJSExecutor.h"

@protocol ToolsExport <JSExport>

- (NSString *)chineseToPinYin:(NSString *)sourceString;
- (void)cancelTimer:(int)indentify;
- (void)hideSoftKeyboard;
- (NSString *)getFileSource:(NSString *)relativePath;
- (NSString *)generateImageByView:(NSString *)viewId :(NSString *)imageName;
- (NSString *)getResString:(NSString *)key;

- (int)setTimer:(double)interval :(double)delay :(BOOL)isRepeat :(JSValue *)callback;

- (void)copyTextToClipboard:(NSString *)text;

@end

@interface Tools : NSObject<ToolsExport>

@property (nonatomic,weak)MRJSExecutor *jsExcutor;

@end
