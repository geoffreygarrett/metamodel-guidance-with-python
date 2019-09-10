from src.surrogate.dataset import DataSetFX, NullTransformFX

ds1 = DataSetFX.from_parquet(
    file_name="dataSet_gridSampled_3.parquet",
    root_dir="data",
    transform=NullTransformFX()
)

ds1.to_mat(f"{ds1.name}.mat", root_dir=ds1.root_dir)
ds1_train, ds1_test = ds1.train_test_split()

ds1_train.to_mat(f"{ds1_train.name}.mat", root_dir=ds1_train.root_dir)
ds1_test.to_mat(f"{ds1_test.name}.mat", root_dir=ds1_test.root_dir)

# ds2 = DataSetFX.from_parquet(
#     file_name="dataSet_gridSampled_3.parquet",
#     root_dir="data",
#     transform=TransformFX
# )

print(ds1.output.size)

# print(ds1[1])

print("train len -l: ", len(ds1_train))
print("train len -o: ", ds1_train.output.shape)
print("\n")
print("test len: -l", len(ds1_test))
print("test len: -o", ds1_test.input.shape)

# print(ds1_train.output.size)


# df = ds1.get_df()
# print(df.name)
# print(train.get_df().name)
# print(test.get_df().name)
