//
//  RatingBar.h
//  mWidget
//
//  Created by Nil on 22/12/14.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol starIndexDelegate <NSObject>
- (void)postStarIndex:(NSUInteger)index andOldIndex:(NSUInteger)oldIndex;
@end
@interface RatingBar : UIView

@property (nonatomic, assign) CGFloat  value;
@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, assign) NSInteger starNumber;
@property (nonatomic, strong) UIImage *topImage;
@property (nonatomic, strong) UIImage *bottomImage;
@property (nonatomic, assign) CGFloat step;
@property (nonatomic, assign) id<starIndexDelegate>delegate;


@end
