//
//  MRControlRectManager.h
//  RectToy
//
//  Created by Lancelot on 2/9/15.
//  Copyright (c) 2015 Lancelot. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRControlRect.h"

@interface MRControlRectManager : NSObject

@property (strong) NSMutableArray* rects;

-(MRControlRect*)createRect:(CGRect)parentFrame;
-(MRControlRect*)generateRect:(MRView*)root;
-(void)clearRects;

@end
