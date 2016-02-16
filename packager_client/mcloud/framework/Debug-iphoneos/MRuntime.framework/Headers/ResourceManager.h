//
//  ResourceManager.h
//  MRuntime
//
//  Created by Lancelot on 2/4/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRAnimation.h"

@interface ResourceManager : NSObject

// when base folder is nil, resource manager searches main bundle
@property(nonatomic, strong) NSString* baseFolder;

@property(nonatomic, strong) NSString* locale;

@property (nonatomic, strong) NSString *appLanguage;


- (instancetype)initWithBaseFolder:(NSString *)baseFolder;
- (instancetype)initWithBaseFolder:(NSString *)baseFolder andLocale:(NSString *)local andAppLanguage:(NSString *)appLanguage;

- (UIImage *)getImage:(NSString *)name;
-(NSString*)getString:(NSString*)key;
-(MRAnimation*)getAnimation:(NSString*)uid;

- (BOOL)resetNineCache;
@end


@interface CompilerResorceManager:ResourceManager

- (instancetype)initWithLocal:(NSString *)local;

@end
