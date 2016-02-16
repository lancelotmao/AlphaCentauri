//
//  MRAjax.h
//  MRuntime
//
//  Created by lucaiguang on 15/11/12.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MRAjaxDelegate <NSObject>
@optional
- (void)didFinishDownloadingWithResponse:(NSHTTPURLResponse *)response withData:(NSData *)resultData;
- (void)didFailWithError:(NSError *)error;
@end

@class JSContext, JSManagedValue, MRJQuery;
@interface MRAjax : NSObject

@property (nonatomic, strong) NSString *identifier;

+ (void)requireWithContext:(JSContext *)context;
+ (NSArray *)getCookies:(NSString *)identifier;

- (void)open:(NSString *)method :(NSString *)url :(BOOL)asynchronous;
- (void)setRequestHeader:(NSString *)headerKey :(NSString *)headerValue;
- (void)send:(NSString *)bodyString;

@property (nonatomic, assign) float timeout;
@property (nonatomic, strong) JSManagedValue *beforeSend;
@property (nonatomic, strong) JSManagedValue *complete;
@property (nonatomic, strong) JSManagedValue *success;
@property (nonatomic, strong) JSManagedValue *error;

@property (nonatomic, weak) id<MRAjaxDelegate> delegate;

@property (nonatomic,strong) MRJQuery *query;

@end
