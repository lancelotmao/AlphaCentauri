//
//  utility.h
//  mWidget
//
//  Created by mCloud on 14/12/17.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#define iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242,2208), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750,1334), [[UIScreen mainScreen] currentMode].size) : NO)


@interface utility : NSObject
/**
 *  colorWithHexString  把js传过来的颜色值，转换为RGB
 *  @param  stringToConvert JSON格式的字符串
 *  @return 返回RGB
 *  @作者 hushifei
 */
+ (UIColor*)colorWithHexString:(NSString *)stringToConvert;

/**
 *  随机颜色产生器串
 *  @return 返回一个UIColor对象
 *  @作者 hushifei
 */
+ (UIColor*)randomColor;

/**
 *  dictionaryWithJsonString  把格式化的JSON格式的字符串转换成字典
 *  @param  jsonString JSON格式的字符串
 *  @return 返回字典--
 *  @作者 kefoqing
 */
+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;
/**
 *  显示弹出窗口
 *  @param  一个MRView对象
 *  @作者 hushifei
 */
+ (void)showDialog:(UIView*)aView;
/**
 *  str  把js传过来的字符串转换为NSArray对象
 *  @param  str格式如：@“1 2 3 4” 中间用空格隔开
 *  @return 返回NSArray
 *  @作者 hushifei
 */
+ (NSArray*)StringToArray:(NSString*)str;

/**
 *  dictionaryWithJsonString  把统一字体格式单位转换成无符号整型数的像素（px）单位
 *  @param  str 12pt或12px或字符串
 *  @return 返回整型pt值
 *  @作者 kefoqing
 */
+ (float)fontSizeWithString:(NSString*)str;

/**
 *  frameSizeWithString  把padding的frame格式单位转换成像素（px）单位
 *  @param  paddingStr @“10pd 20dp 30dp 40dp”的字符串
 *  @return 返回px单位的数组
 *  @作者 kefoqing
 */
+ (NSArray*)frameSizeWithString:(NSString *)paddingStr;

/**
 *  imageWithString:  传入一个字符串生成一张图片
 *  @param  url 图片的本地地址或者图片的远程的URL
 *  @return 一张图片
 *  @作者 houyueteng
 */
+ (UIImage*)imageWithString:(NSString*)url;

+ (UIImage*) OriginImage:(UIImage *)image scaleToSize:(CGSize)size;

/**
 *  imageWithColor:  传入RGB字符串生产一张图片
 *  @param  colorStr 生成图片的颜色 尊守 colorWithHexString方法
 *  @return 一张图片
 *  @作者 hushifei
 */

+ (UIImage*)imageWithColor:(NSString*)colorStr;

+(NSDictionary*)dictionaryFromString:(NSString*)string;

+(NSDictionary*)dictionaryFromeBindingString:(NSString*)string;

+ (NSString *)arrayToString:(NSMutableArray *)arr;

+(void)runUIThread:(dispatch_block_t)block;

+ (CGSize)measureTextSize :(NSString *)text andTextSize :(CGFloat)fontSize;

/**
 * Date/Time util
 */
+ (NSString *)stringFromDate:(NSDate *)date withFormat:(NSString *)format;

@end
