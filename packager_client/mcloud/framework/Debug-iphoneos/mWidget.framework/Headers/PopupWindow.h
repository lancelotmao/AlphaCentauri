//
//  MRPopupWindow.h
//
//  Created by xiekw on 11/14/14.
//  Copyright (c) 2014 xiekw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRView.h"

typedef NS_ENUM(NSUInteger, MRPopupWindowPosition) {
    MRPopupWindowPositionUp = 1,
    MRPopupWindowPositionDown,
};

typedef NS_ENUM(NSUInteger, MRPopupWindowMaskType) {
    MRPopupWindowMaskTypeBlack,
    MRPopupWindowMaskTypeNone,
};


@interface PopupWindow : UIView

+ (instancetype)popover;

/**
 *  If the popover is stay up or down the showPoint
 */
@property (nonatomic, assign, readonly) MRPopupWindowPosition popoverPosition;

@property (nonatomic, weak) UIView *containerView;
@property (nonatomic, weak) UIView *contentView;
/**
 *  The popover arrow size, default is {10.0, 10.0};
 */
@property (nonatomic, assign) CGSize arrowSize;

/**
 *  The popover corner radius, default is 7.0;
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 *  The popover animation show in duration, default is 0.4;
 */
@property (nonatomic, assign) CGFloat animationIn;

/**
 *  The popover animation dismiss duration, default is 0.3;
 */
@property (nonatomic, assign) CGFloat animationOut;

/**
 *  If the drop in animation using spring animation, default is YES;
 */
@property (nonatomic, assign) BOOL animationSpring;

/**
 *  The background of the popover, default is MRPopupWindowMaskTypeBlack;
 */
@property (nonatomic, assign) MRPopupWindowMaskType maskType;

/**
 *  when you using atView show API, this value will be used as the distance between popovers'arrow and atView. Note: this value is invalid when popover show using the atPoint API
 */
@property (nonatomic, assign) CGFloat betweenAtViewAndArrowHeight;


/**
 * Decide the nearest edge between the containerView's border and popover, default is 4.0
 */
@property (nonatomic, assign) CGFloat sideEdge;

/**
 *  The callback when popover did show in the containerView
 */
@property (nonatomic, copy) dispatch_block_t didShowHandler;

/**
 *  The callback when popover did dismiss in the containerView;
 */
@property (nonatomic, copy) dispatch_block_t didDismissHandler;
//@property (nonatomic, strong) MRView *superView;
/**
 *  Show API
 *
 *  @param point         the point in the container coordinator system.
 *  @param position      stay up or stay down from the showAtPoint
 *  @param contentView   the contentView to show
 *  @param containerView the containerView to contain
 */
- (void)showAtPoint:(CGPoint)point popoverPostion:(MRPopupWindowPosition)position withContentView:(UIView *)contentView inView:(UIView *)containerView;

/**
 *  Lazy show API        The show point will be caluclated for you, try it!
 *
 *  @param atView        The view to show at
 *  @param position      stay up or stay down from the atView, if up or down size is not enough for contentView, then it will be set correctly auto.
 *  @param contentView   the contentView to show
 *  @param containerView the containerView to contain
 */
- (void)showAtView:(UIView *)atView popoverPostion:(MRPopupWindowPosition)position withContentView:(UIView *)contentView inView:(UIView *)containerView;

/**
 *  Lazy show API        The show point and show position will be caluclated for you, try it!
 *
 *  @param atView        The view to show at
 *  @param contentView   the contentView to show
 *  @param containerView the containerView to contain 
 */
- (void)showAtView:(UIView *)atView withContentView:(UIView *)contentView inView:(UIView *)containerView;

- (void)dismiss;


@end
