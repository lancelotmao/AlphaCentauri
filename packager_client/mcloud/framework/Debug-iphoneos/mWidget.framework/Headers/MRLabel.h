//
//  MRLabel.h
//  mWidget
//
//  Created by mCloud on 14/11/29.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRView.h"
@class DeLabel;

@interface MRLabel : MRView<MRJSView>
@property(nonatomic,readonly,strong) UILabel *label;
- (CGSize)measureTextSize;
@end
