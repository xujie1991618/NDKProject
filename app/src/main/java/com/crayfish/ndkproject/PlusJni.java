package com.crayfish.ndkproject;

/**
 * ============================
 * 作    者：crayfish(徐杰)
 * 创建日期：2017/9/21.
 * 描    述：
 * 修改历史：
 * ===========================
 */

public class PlusJni {

    static {
        System.loadLibrary("native-plus-lib");
    }

    public native int plusNumbers(int x,int y);

}
