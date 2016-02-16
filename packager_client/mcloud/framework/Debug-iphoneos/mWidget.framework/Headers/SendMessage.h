//
//  SendMessage.h
//  mWidget
//
//  Created by chengxinqing on 15/5/8.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRView.h"

@interface SendMessage : MRView
- (void)sendSmsForJS:(NSArray *)phone :(NSString *)body;
@end
