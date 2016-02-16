//
//  TextInput.h
//  MRuntime
//
//  Created by Nil on 30/4/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TextInput : UITextField
@property (nonatomic, assign)CGSize autoSize;
- (CGSize)measureTextSize:(UIFont*)font;

@end
