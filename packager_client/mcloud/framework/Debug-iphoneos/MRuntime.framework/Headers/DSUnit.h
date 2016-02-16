//
//  DSUnit.h
//  MRuntime
//
//  Created by lancemao on 7/21/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DSUnit : NSObject

@property (nonatomic, strong) NSString* bundle;
@property (nonatomic, strong) NSString* method;
@property (nonatomic, strong) NSString* actionId;
@property (nonatomic, strong) NSMutableDictionary* arguments;

@property (weak) DSUnit* yParent;
@property (weak) DSUnit* nParent;

@property (strong) DSUnit* sucAction;
@property (strong) DSUnit* failAction;
@property (strong) DSUnit* doneAction;
@property (strong) DSUnit* callbackAction;


-(instancetype) initFromUnit:(DSUnit*)unit;

- (DSUnit*)getYChild;
- (DSUnit*)getNChild;
- (BOOL)hasParent;

@end
