//
//  RsaCrypt4iOS.h
//  Test
//
//  Created by mCloud on 15/4/3.
//  Copyright (c) 2015年 mCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

// rsa加密解密模式：RSA/ECB/PKCS1Padding

@interface RsaCrypt4iOS : NSObject

/**************************************************************/
// 用rsa公钥加密数据
// 参数:
//			strPfxKey-[IN]pfx格式的公钥文件（经base64加密过）
//			strPfxPass-[IN]pfx文件的密钥
//			pIn-[IN]原文
//			nInLen-[IN]pIn中数据字节数
//			pDest-[OUT]保存 经base64加密过的密文
//			nOutLen-[IN/OUT] 作为输入：pDest的字节数    作为输出：保存到pDest的数据字节数
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmRsaPubEncrypt:(NSString *)strPfxKey PfxPass:(NSString *)strPfxPass pIn:(unsigned char *)pIn nInLen:(int)nInLen pDest:(unsigned char *)pDest nOutLen:(int *)nOutLen;

/**************************************************************/
// 用rsa公钥解密数据
// 参数:
//			strPfxKey-[IN]pfx格式的公钥文件（经base64加密过）
//			strPfxPass-[IN]pfx文件的密钥
//			pIn-[IN]base64加密过的密文
//			nInLen-[IN]pIn中数据字节数
//			pDest-[OUT]保存原文
//			nOutLen-[IN/OUT] 作为输入：pDest的字节数    作为输出：保存到pDest的数据字节数
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmRsaPubDecrypt:(NSString *)strPfxKey PfxPass:(NSString *)strPfxPass pIn:(unsigned char *)pIn nInLen:(int)nInLen pDest:(unsigned char *)pDest nOutLen:(int *)nOutLen;

/**************************************************************/
// 用rsa私钥加密数据
// 参数:
//			strPfxKey-[IN]pfx格式的公钥文件（经base64加密过）
//			strPfxPass-[IN]pfx文件的密钥
//			pIn-[IN]原文
//			nInLen-[IN]pIn中数据字节数
//			pDest-[OUT]保存 经base64加密过的密文
//			nOutLen-[IN/OUT] 作为输入：pDest的字节数    作为输出：保存到pDest的数据字节数
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmRsaPrivEncrypt:(NSString *)strPfxKey PfxPass:(NSString *)strPfxPass pIn:(unsigned char *)pIn nInLen:(int)nInLen pDest:(unsigned char *)pDest nOutLen:(int *)nOutLen;

/**************************************************************/
// 用rsa私钥解密数据
// 参数:
//			strPfxKey-[IN]pfx格式的公钥文件（经base64加密过）
//			strPfxPass-[IN]pfx文件的密钥
//			pIn-[IN]base64加密过的密文
//			nInLen-[IN]pIn中数据字节数
//			pDest-[OUT]保存原文
//			nOutLen-[IN/OUT] 作为输入：pDest的字节数    作为输出：保存到pDest的数据字节数
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)DtmRsaPrivDecrypt:(NSString *)strPfxKey PfxPass:(NSString *)strPfxPass pIn:(unsigned char *)pIn nInLen:(int)nInLen pDest:(unsigned char *)pDest nOutLen:(int *)nOutLen;

/**************************************************************/
// 校验rsa证书在当前时间下的有效性
// 参数:
//			strPfxKey-[IN]pfx格式的公钥文件（经base64加密过）
//			strPfxPass-[IN]pfx文件的密钥
// 返回值: YES-有效，NO-无效
/**************************************************************/
- (BOOL)DtmRsaCheckCertByTime:(NSString *)strPfxKey PfxPass:(NSString *)strPfxPass;

@end
