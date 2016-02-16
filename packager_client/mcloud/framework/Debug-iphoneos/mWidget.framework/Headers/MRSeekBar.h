//
//  MRSeekBar.h
//  mWidget
//
//  Created by rossyang on 14/12/9.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRView.h"
@class MRUISeekBar;
@interface MRSeekBar : MRView<MRJSView>
@property (nonatomic,strong,readonly) MRUISeekBar *slide;

@end
