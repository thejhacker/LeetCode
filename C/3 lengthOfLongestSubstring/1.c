﻿int lengthOfLongestSubstring(char * s){
    int prior = 0; //上次状态下最长子串的长度
    int left = 0;
    int dict[256] = {0}; //映射ASCII码
    int right = 1; //表示字符串中第right个字符
    int i;

    while(*s != '\0'){
        i = *s-0; //字符转换为整数
        if(dict[i] > left)    
            left = dict[i];
        dict[i] = right;
        prior = (prior>right-left)?prior:right-left; //right的值比对应的数组下标大1
        s++;
        right++;
    }
    return prior;
}

//思路：将n个字符划分为前n-1个字符和第n个字符两个子集，当遍历第n个字符时，显然，前n-1个字符中无重复的最长子串长度是已知的（不妨设为prior），
//要确定n个字符所构成的字符串中无重复的最长子串长度，只需要再确定这n个包含第n个字符的字符串中无重复的最长子串长度（不妨设为len），max{
//prior, len}即为n个字符中无重复的最长子串长度（手动狗头，感觉有点数学归纳法证明不等式的味道，捂脸😀这个算法我憋了两天才想到
//，纪念一下）


著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//作者：jack-153
//链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/3wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-jack-1/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。