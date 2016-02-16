//
//  MRLayoutParams.h
//  mWidget
//
//  Created by mCloud on 14/12/19.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>


@class MRView;

typedef enum {
    FIX_SIZE,   // Respects the view's frame size
    WRAP_CONTENT,   // Adjusts the frame to fill the linear layout view
    MATCH_PARENT,
} Layout_Fill_Mode;  //modify 1
typedef struct {
    CGFloat top;
    CGFloat left;
    CGFloat bottom;
    CGFloat right;
}Margin;
typedef struct {
    CGFloat top;
    CGFloat left;
    CGFloat bottom;
    CGFloat right;
}Padding;

typedef enum {
    unkonw,
    left,
    right,
    top,
    bottom,
    center,
}Alignment;

@interface MRLayoutParams : NSObject
@property(nonatomic,assign) float width;
@property(nonatomic,assign) float height;
//@property (nonatomic,assign)Layout_Fill_Mode fillMode;

@property (nonatomic,assign)Layout_Fill_Mode widthFillMode;
@property (nonatomic,assign)Layout_Fill_Mode heightFillMode;


@property (nonatomic,assign) float weight;
@property (nonatomic,assign) Margin margin;
@property (nonatomic,assign) Padding padding;
@property (nonatomic,assign) Alignment layoutGravity;
@property (nonatomic,assign) Alignment gravityHorizontal;
@property (nonatomic,assign) Alignment gravityVertical;



Padding makePadding(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right);
Margin makeMargin(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right);

- (instancetype)init;
- (instancetype)initWithView:(MRView*)view;

@end
