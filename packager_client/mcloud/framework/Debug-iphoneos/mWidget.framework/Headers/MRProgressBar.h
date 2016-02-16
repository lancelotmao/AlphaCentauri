//
//  MRProgressBar.h
//  mWidget
//
//  Created by mCloud on 14/12/11.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRView.h"

@interface MRProgressBar : MRView<MRJSView>
@property(nonatomic,readonly,strong) UIProgressView *progressView;
@end
