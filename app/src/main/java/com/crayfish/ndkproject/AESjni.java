package com.crayfish.ndkproject;

/**
 * ============================
 * 作    者：crayfish(徐杰)
 * 创建日期：2017/9/30.
 * 描    述：
 * 修改历史：
 * ===========================
 */

public class AESjni {

    static {
        System.loadLibrary("AESjni");//之前在build.gradle里面设置的so名字，必须一致
    }

    public static native String myEncrypt(String content);

    public static native String myDecrypt(String content);

    public static String encrypt(String key,String palinText) throws Exception{
        //加密
        return "123";
    }

    public static String decrypt(String key,String palinText) throws Exception{
        //解密
        return "456";
    }
}
