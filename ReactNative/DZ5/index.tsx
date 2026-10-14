import { Controller, useForm } from "react-hook-form";
import { Button, Text, TextInput, View } from "react-native";

export default function Index() {

  const { control, handleSubmit, formState: { errors } } = useForm();
  const onSubmit = (data: any) => { console.log(data) };

  return (
    <View
      style={{
        flex: 1,
        justifyContent: "center",
        alignItems: "center",
        backgroundColor: "#ccc",
        padding: 16
      }}
    >
      <View
        style={{
          width: "90%",
          backgroundColor: "#fff",
          padding: 16,
          borderRadius: 12
        }}
      >
        <Text style={{ fontSize: 18, fontWeight: "700", marginBottom: 12 }}>
          React Hook Form
        </Text>

        {/* login */}
        <Controller
          name="login"
          control={control}
          rules={{ required: true, maxLength: { value: 32, message: "Max length is 32" } }}
          render={({ field: { onChange, value } }) =>
            <TextInput
              value={value}
              onChangeText={onChange}
              placeholder="Enter login"
              placeholderTextColor="#94a3b8"
              style={{
                borderWidth: 1,
                borderColor: "#e2e8f0",
                borderRadius: 8,
                padding: 10,
                marginBottom: 6
              }}
            />
          }
        />
        {errors.login && (
          <Text style={{ color: "crimson", marginBottom: 8 }}>
            This field is required.
          </Text>
        )}

        {/* password */}
        <Controller
          name="password"
          control={control}
          rules={{
            required: true,
            minLength: { value: 6, message: "Min length is 6" },
            maxLength: { value: 64, message: "Max length is 64" }
          }}
          render={({ field: { onChange, value } }) =>
            <TextInput
              value={value}
              onChangeText={onChange}
              placeholder="Enter password"
              placeholderTextColor="#94a3b8"
              secureTextEntry={true}
              style={{
                borderWidth: 1,
                borderColor: "#e2e8f0",
                borderRadius: 8,
                padding: 10,
                marginBottom: 6
              }}
            />
          }
        />
        {errors.password && (
          <Text style={{ color: "crimson", marginBottom: 8 }}>
            This field is required.
          </Text>
        )}

        <Button title="Send data" onPress={handleSubmit(onSubmit)} />
      </View>
    </View>
  );
}
