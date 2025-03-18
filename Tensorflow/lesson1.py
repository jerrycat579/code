import torch
from transformers import BertTokenizer, BertModel
from sklearn.metrics.pairwise import cosine_similarity
import numpy as np

# 加载BERT模型和分词器
tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')
model = BertModel.from_pretrained('bert-base-uncased')

# 将文本转化为BERT输入的格式
def encode_text(text):
    inputs = tokenizer(text, return_tensors='pt', padding=True, truncation=True, max_length=512)
    return inputs

# 获取文本的BERT嵌入向量
def get_bert_embeddings(text):
    inputs = encode_text(text)
    with torch.no_grad():
        outputs = model(**inputs)
    # 取[CLS]的嵌入向量作为句子的表示
    embeddings = outputs.last_hidden_state[:, 0, :]
    return embeddings

# 计算两个文本之间的余弦相似度
def calculate_similarity(text1, text2):
    embedding1 = get_bert_embeddings(text1)
    embedding2 = get_bert_embeddings(text2)
    
    # 转为numpy数组，并计算余弦相似度
    embedding1 = embedding1.cpu().numpy()
    embedding2 = embedding2.cpu().numpy()
    similarity = cosine_similarity(embedding1, embedding2)
    
    return similarity[0][0]
# 示例文本
text1 = "Deep learning is a subfield of machine learning."
text2 = "Deep learning is a subset of machine learning."
# 计算相似度
similarity_score = calculate_similarity(text1, text2)
print(f"Similarity score: {similarity_score}")
# 判断是否重复（阈值可以根据具体需求调整）
threshold = 0.8
if similarity_score > threshold:
    print("The texts are similar (or duplicated).")
else:
    print("The texts are not similar.")
