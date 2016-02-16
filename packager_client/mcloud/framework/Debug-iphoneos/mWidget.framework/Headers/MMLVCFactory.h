//
//  MMLVCFactory.h
//  MMLInflater
//
//  Created by Lance Mao on 1/16/15.
//  Copyright (c) 2015 Huawei. All rights reserved.
//
#import "MRViewController.h"
#import "MRFragment.h"
@interface MMLVCFactory : NSObject

+ (MRViewController*)createVCFromFile:(MRViewController*)vc :(NSString*) filePath :(id)projectName;
+ (void)loadFragment:(MRFragment*)fragment :(NSString*)fileName :(NSData*)pgData :(NSData*)actData;
+ (UIView *)refreshMML:(MRViewController*)vc :(NSString*)mmlData :(NSString*)act :(NSString*)fileName;
+ (void)setCustomExecutorName:(NSString*)name;

@end
