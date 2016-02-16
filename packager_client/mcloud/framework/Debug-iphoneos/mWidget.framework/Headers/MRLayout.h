//
//  MRLayout.h
//  mWidget
//
//  Created by mCloud on 14/12/15.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRView.h"
#import "MRLayoutParams.h"

@interface MRLayout : MRView

@property (nonatomic,assign) CGSize size;
@property (nonatomic,assign) BOOL layoutDone;

- (void)addView:(MRView *)view;
- (void)insertView:(MRView *)view insertAtIndex:(int)Index;
- (void)doLayout:(CGSize)parentSize;
- (void)resetLayout;
- (MRLayout*)findRootLayout;
- (void)onclick:(id)sender;

@end
