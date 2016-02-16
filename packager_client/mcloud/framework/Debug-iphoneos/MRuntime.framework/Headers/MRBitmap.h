//
//  MRBitmap.h
//  MRuntime
//
//  Created by lucaiguang on 15/11/10.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MRBitmap : NSObject
+ (MRBitmap *)bitmapWithSize:(CGSize)size config:(NSDictionary *)config;
@property (nonatomic, strong) UIImage *image;
@end
