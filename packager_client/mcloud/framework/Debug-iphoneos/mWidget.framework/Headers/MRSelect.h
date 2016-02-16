//
//  MRSelect.h
//  mWidget
//
//  Created by mCloud on 14/12/8.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRView.h"
@class SelectView;
@interface MRSelect : MRView<MRJSView>
@property(nonatomic,readonly)SelectView *Select;
@end
