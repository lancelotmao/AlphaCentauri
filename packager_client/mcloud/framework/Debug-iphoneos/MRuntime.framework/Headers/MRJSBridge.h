//
//  MRJSBridge.h
//  MRuntime
//
//  Created by lucaiguang on 15/11/28.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import <JavaScriptCore/JavaScriptCore.h>
#import "MRBaseView.h"
#import "MRBitmap.h"
#import "MRBaseViewController.h"
#import "FileSource.h"

// forward declaration
@class MRView;

@protocol MRJSBridgeExport <JSExport>

@property (nonatomic, strong) MRView *body;

- (id)f;
- (void)post;
- (NSString *)getEnvironment;
- (BOOL)getUniportal;
- (MRBaseView *)getElementById:(NSString *)viewId;
- (void)showActionSheet:(NSArray*)options :(JSValue*)callback;
- (void)pick:(JSValue*)callback :(JSValue*)param; // param has type property and 0 gallery; 1 camera
- (MRBitmap *)createScaledBitmap:(MRBitmap *)bitmap :(NSNumber *)width :(NSNumber *)height;
- (BOOL)unzip:(NSString *)oldFileName :(NSString *)newFileName;
- (void)postDelayed:(JSValue *)callback :(NSNumber *)time;
- (void)openFile:(NSString *)path;
@end


@interface MRJSBridge : NSObject <MRJSBridgeExport>

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *basePath;
@property (nonatomic, weak) MRBaseViewController* pageDelegate;

/*!
 @property
 @abstract file source can be used for file manipulations
 @discussion
 */
@property (nonatomic, strong) MMLFileSource *fileSource;

+ (void)clearModuleCache;

- (JSValue *)evaluateScript:(NSString *)script;
- (JSValue *)evaluateScript:(NSString *)script withSourceURL:(NSURL *)sourceURL;
- (JSValue *)objectForKeyedSubscript:(id)key;
- (void)setObject:(id)object forKeyedSubscript:(NSObject <NSCopying> *)key;
@end