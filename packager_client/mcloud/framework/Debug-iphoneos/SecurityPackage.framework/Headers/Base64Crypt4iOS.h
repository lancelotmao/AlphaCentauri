//
//  Base64Crypt4iOS.h
//  test-dtm
//
//  Created by mcloud on 15/4/14.
//  Copyright (c) 2015年 mcloud. All rights reserved.
//

#import <Foundation/Foundation.h>

// Base64加密解密

@interface Base64Crypt4iOS : NSObject

/**************************************************************/
// 加密数据
// 参数:
//			pIn-[IN]原文
//			nInLen-[IN]pIn中数据字节数
//			pDest-[OUT]保存密文
//			nOutLen-[IN/OUT] 作为输入：pDest的字节数    作为输出：保存到pDest的数据字节数
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmBase64Encrypt:(unsigned char *)pIn nInLen:(int)nInLen pDest:(unsigned char *)pDest nOutLen:(int *)nOutLen;

/**************************************************************/
// 解密数据
// 参数:
//			pIn-[IN]密文
//			nInLen-[IN]pIn中数据字节数
//			pDest-[OUT]保存原文
//			nOutLen-[IN/OUT] 作为输入：pDest的字节数    作为输出：保存到pDest的数据字节数
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmBase64Decrypt:(unsigned char *)pIn nInLen:(int)nInLen pDest:(unsigned char *)pDest nOutLen:(int *)nOutLen;

@end
