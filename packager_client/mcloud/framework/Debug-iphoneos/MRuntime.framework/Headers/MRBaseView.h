//
//  MRBaseView.h
//  MRuntime
//
//  Created by lancemao on 12/7/15.
//  Copyright © 2015 Huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JSValue, MRContext;
@interface MRBaseView : NSObject

@property (nonatomic,weak) MRContext* context;

- (void)setAttribute:(NSString *)attr fromKeyStr:(NSString *)value;
- (id)getAttribute:(NSString *)attr;
- (void)setEventHandler:(JSValue *)handler forKey:(NSString *)key;
- (void)setEvent:(NSString *)event :(NSString *)jsCode;

@end
